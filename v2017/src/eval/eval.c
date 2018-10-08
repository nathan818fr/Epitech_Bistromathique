#include "bistro.h"
#include "bistro_eval.h"
#include "bistro_utils.h"

void eval_parse(eval_ctx_t *ctx)
{
	while (ctx->curpos < ctx->bistro->expr_len) {
		ctx->curchar = ctx->bistro->expr[ctx->curpos];
		if (!eval_brace(ctx) && !eval_op(ctx) && !eval_nb(ctx))
			BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG,
				     "impossible");
		ctx->curpos = ctx->curpos + 1;
	}
}

char *eval_finalize(eval_ctx_t *ctx)
{
	number_t *res_nb = ctx->curres;
	char *str;

	if (res_nb == NULL)
		BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "incomplete final");
	if (ctx->curstack != NULL)
		BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "incomplete branch");
	str = number_to_string(ctx->bistro, number_fix(res_nb));
	number_free(res_nb);
	return (str);
}

char *eval(bistro_t *bistro)
{
	eval_ctx_t ctx;

	my_memset(&ctx, 0, sizeof(eval_ctx_t));
	ctx.bistro = bistro;
	eval_brace_push(&ctx);
	eval_parse(&ctx);
	eval_brace_pop(&ctx, 1);
	return (eval_finalize(&ctx));
}