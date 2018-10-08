#include "bistro_eval.h"

void eval_branch_insert_rightnb(eval_ctx_t *ctx)
{
	eval_branch_t *nb_branch;

	nb_branch = eval_branch_create(
		OP_NBR, eval_create_reset_curnb(ctx), -1);
	if (ctx->curstack->branch == NULL)
		ctx->curstack->branch = nb_branch;
	else {
		eval_branch_set_right(ctx->curstack->branch, nb_branch);
		eval_branch_calc(ctx->bistro, &ctx->curstack->branch,
				ctx->curstack->branch);
	}
}

void eval_branch_insert_op_start(eval_branch_t **branch,
	eval_op_branchs_t *op_branchs)
{
	eval_branch_set_left(op_branchs->opb, op_branchs->nbb);
	*branch = op_branchs->opb;
}

void eval_branch_insert_op_prio_in(bistro_t *bistro, eval_branch_t **branch,
	eval_op_branchs_t *op_branchs, int prio)
{
	eval_branch_t *calc_branch;

	eval_branch_set_right(*branch, op_branchs->nbb);
	calc_branch = *branch;
	while ((*branch)->parent != NULL &&
	       (*branch)->parent->priority == prio) {
		*branch = (*branch)->parent;
	}
	if ((*branch)->parent) {
		(*branch)->parent->right = NULL;
		eval_branch_set_right((*branch)->parent, op_branchs->opb);
		(*branch)->parent = NULL;
	}
	eval_branch_set_left(op_branchs->opb, *branch);
	*branch = op_branchs->opb;
	eval_branch_calc(bistro, branch, calc_branch);
}

void eval_branch_insert_op_prio(bistro_t *bistro, eval_branch_t **branch,
	eval_op_branchs_t *op_branchs, int prio)
{
	if ((*branch)->priority < prio) {
		eval_branch_set_left(op_branchs->opb, op_branchs->nbb);
		eval_branch_set_right(*branch, op_branchs->opb);
		*branch = op_branchs->opb;
	} else
		eval_branch_insert_op_prio_in(
			bistro, branch, op_branchs, prio);
}

void eval_branch_insert_op(bistro_t *bistro, eval_branch_t **branch,
	eval_insert_op_t *insert_op)
{
	eval_op_branchs_t op_branchs;

	op_branchs.opb = eval_branch_create(
		insert_op->op, NULL, insert_op->priority);
	op_branchs.nbb = eval_branch_create(OP_NBR, insert_op->nb, -1);
	if (*branch)
		eval_branch_insert_op_prio(
			bistro, branch, &op_branchs, insert_op->priority);
	else
		eval_branch_insert_op_start(branch, &op_branchs);
}
