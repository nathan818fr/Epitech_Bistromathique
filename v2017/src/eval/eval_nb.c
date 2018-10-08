#include "bistro_utils.h"
#include "bistro_eval.h"

int eval_nb(eval_ctx_t *ctx)
{
	if (number_char_val(ctx->bistro, ctx->curchar) == -1)
		BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "not number");
	if (ctx->curres != NULL)
		BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "already has res");
	if (ctx->curnb.start == NULL ||
		*(ctx->curnb.start) == ctx->bistro->base[0]) {
		ctx->curnb.start = (ctx->bistro->expr + ctx->curpos);
		ctx->curnb.len = 0;
	}
	ctx->curnb.len = ctx->curnb.len + 1;
	return (1);
}
