#include "bistro_calc.h"
#include "bistro_eval.h"

void eval_branch_calc_replace(eval_branch_t **old_branch,
	eval_branch_t *new_branch)
{
	eval_branch_t *parent;
	char is_left = 0;

	parent = (*old_branch)->parent;
	if (parent)
		is_left = (parent->left == *old_branch);
	eval_branch_free((*old_branch)->left);
	eval_branch_free((*old_branch)->right);
	eval_branch_free(*old_branch);
	if (parent) {
		if (is_left)
			parent->left = new_branch;
		else
			parent->right = new_branch;
		*old_branch = parent;
	} else
		*old_branch = new_branch;
}

void eval_branch_calc(bistro_t *bistro, eval_branch_t **cur_branch,
	eval_branch_t *calc_branch)
{
	eval_branch_t *nbranch;

	while (1) {
		if (calc_branch->op == OP_NBR)
			return;
		if (calc_branch->left == NULL || calc_branch->right == NULL ||
			calc_branch->left->op != OP_NBR ||
			calc_branch->right->op != OP_NBR)
			return;
		nbranch = eval_branch_create(
			OP_NBR,
			calc(calc_branch->left->nb, calc_branch->right->nb,
			calc_branch->op, bistro), -1);
		if (calc_branch == *cur_branch) {
			eval_branch_calc_replace(&calc_branch, nbranch);
			*cur_branch = calc_branch;
		} else
			eval_branch_calc_replace(&calc_branch, nbranch);
	}
}
