#include "bistro_utils.h"
#include "bistro_eval.h"

void eval_brace_push(eval_ctx_t *ctx)
{
	if (eval_has_nb_or_res(ctx))
		BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "bad open bracket");
	eval_stack_push(&ctx->curstack);
}

void eval_brace_pop(eval_ctx_t *ctx, int is_end)
{
	if (!is_end && ctx->curstack->parent == NULL)
		BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "bad close bracket");
	if (!eval_has_nb_or_res(ctx))
		BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "bad bracket end");
	eval_branch_insert_rightnb(ctx);
	ctx->curres = ctx->curstack->branch->nb;
	if (ctx->curres == NULL)
		BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG,
			"incalculable branch");
	ctx->curstack->branch->nb = NULL;
	eval_branch_free(ctx->curstack->branch);
	eval_stack_pop(&ctx->curstack);
}

int eval_brace(eval_ctx_t *ctx)
{
	if (ctx->curchar == ctx->bistro->ops[OP_OPEN_PARENT_IDX]) {
		eval_brace_push(ctx);
		return (1);
	}
	if (ctx->curchar == ctx->bistro->ops[OP_CLOSE_PARENT_IDX]) {
		eval_brace_pop(ctx, 0);
		return (1);
	}
	return (0);
}
