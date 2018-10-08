#include "bistro_utils.h"
#include "bistro_number.h"
#include "bistro_eval.h"

eval_branch_t *eval_branch_create(int op, number_t *nb, int priority)
{
	eval_branch_t *branch;

	branch = bistro_malloc(sizeof(eval_branch_t));
	my_memset(branch, 0, sizeof(eval_branch_t));
	branch->op = op;
	branch->nb = nb;
	branch->priority = priority;
	return (branch);
}

void eval_branch_free(eval_branch_t *branch)
{
	if (branch) {
		number_free(branch->nb);
		free(branch);
	}
}
