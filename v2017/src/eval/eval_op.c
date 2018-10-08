#include "bistro_utils.h"
#include "bistro_eval.h"

int eval_op_index(bistro_t *bistro, char c)
{
	int i = 0;

	while (i < OPS_SIZE) {
		if (bistro->ops[i] == c)
			return (i);
		i = i + 1;
	}
	return (-1);
}

int eval_op_priority(int op)
{
	if (op == OP_MULT_IDX || op == OP_DIV_IDX || op == OP_MOD_IDX)
		return (1);
	return (0);
}

int eval_op_neg(eval_ctx_t *ctx, int op)
{
	if (op == OP_PLUS_IDX)
		return (1);
	else if (op == OP_NEG_IDX) {
		ctx->curstack->curneg = !ctx->curstack->curneg;
		return (1);
	}
	return (0);
}

int eval_op(eval_ctx_t *ctx)
{
	int op;
	number_t *nb;
	eval_insert_op_t insert_op;

	op = eval_op_index(ctx->bistro, ctx->curchar);
	if (op == -1)
		return (0);
	if (!eval_has_nb_or_res(ctx)) {
		if (!eval_op_neg(ctx, op))
			BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "badop");
		return (1);
	}
	nb = eval_create_reset_curnb(ctx);
	insert_op.op = op;
	insert_op.priority = eval_op_priority(op);
	insert_op.nb = nb;
	eval_branch_insert_op(ctx->bistro, &ctx->curstack->branch, &insert_op);
	return (1);
}