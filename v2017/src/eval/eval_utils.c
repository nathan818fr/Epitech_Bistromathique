#include "bistro_utils.h"
#include "bistro_eval.h"

void eval_copy_curnb(eval_ctx_t *ctx, number_t *nb) {
	size_t i = 0;

	while (i < ctx->curnb.len) {
		nb->str[i] = (nbchar_t) number_char_val(
			ctx->bistro,
			ctx->curnb.start[ctx->curnb.len - i - 1]);
		i = i + 1;
	}
}

void eval_reset_curnb(eval_ctx_t *ctx) {
	ctx->curnb.start = NULL;
	ctx->curnb.len = 0;
	ctx->curres = NULL;
}

number_t *eval_create_reset_curnb(eval_ctx_t *ctx)
{
	number_t *nb;

	if (ctx->curres != NULL) {
		if (ctx->curnb.start != NULL)
			BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "res&nb");
		nb = ctx->curres;
	} else if (ctx->curnb.start != NULL) {
		nb = number_create(ctx->curnb.len);
		eval_copy_curnb(ctx, nb);
	} else {
		BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "not cur nb");
		return (0);
	}
	if (ctx->curstack->curneg) {
		ctx->curstack->curneg = 0;
		nb->is_neg = !nb->is_neg;
		number_fix(nb);
	}
	eval_reset_curnb(ctx);
	return (nb);
}

int eval_has_nb_or_res(eval_ctx_t *ctx)
{
	return (ctx->curnb.start != NULL || ctx->curres != NULL);
}
