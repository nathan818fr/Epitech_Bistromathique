#include "bistro_eval.h"
#include "bistro_utils.h"

void eval_branch_set_left(eval_branch_t *parent, eval_branch_t *to_left)
{
	if (to_left && to_left->parent)
		BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "left has parent");
	if (parent->left)
		BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "parent has left");
	parent->left = to_left;
	if (to_left)
		to_left->parent = parent;
}

void eval_branch_set_right(eval_branch_t *parent, eval_branch_t *to_right)
{
	if (to_right && to_right->parent)
		BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "right has parent");
	if (parent->right)
		BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "parent has right");
	parent->right = to_right;
	if (to_right)
		to_right->parent = parent;
}
