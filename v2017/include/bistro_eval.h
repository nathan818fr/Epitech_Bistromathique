#ifndef BISTRO_EVAL_H_
#define BISTRO_EVAL_H_

#include "bistro.h"
#include "bistro_number.h"

typedef struct eval_branch_s {
	int op;
	number_t *nb;
	int priority;
	struct eval_branch_s *parent;
	struct eval_branch_s *left;
	struct eval_branch_s *right;
} eval_branch_t;

typedef struct eval_number_s {
	const char *start;
	size_t len;
} eval_number_t;

typedef struct eval_stack_s {
	char curneg;
	eval_branch_t *branch;
	struct eval_stack_s *parent;
} eval_stack_t;

typedef struct eval_ctx_s {
	bistro_t *bistro;
	size_t curpos;
	char curchar;
	eval_number_t curnb;
	number_t *curres;
	eval_stack_t *curstack;
} eval_ctx_t;

typedef struct eval_insert_op_s {
	int op;
	number_t *nb;
	int priority;
} eval_insert_op_t;

typedef struct eval_op_branchs_s {
	eval_branch_t *opb;
	eval_branch_t *nbb;
} eval_op_branchs_t;

/*
** eval/eval.c
*/
char *eval(bistro_t *bistro);

/*
** eval/eval_stack.c
*/
void eval_stack_push(eval_stack_t **stack);
void eval_stack_pop(eval_stack_t **stack);

/*
** eval/eval_brace.c
*/
int eval_brace(eval_ctx_t *ctx);
void eval_brace_push(eval_ctx_t *ctx);
void eval_brace_pop(eval_ctx_t *ctx, int is_end);

/*
** eval/eval_op.c
*/
int eval_op(eval_ctx_t *ctx);

/*
** eval/eval_nb.c
*/
int eval_nb(eval_ctx_t *ctx);

/*
** eval/eval_utils.c
*/
number_t *eval_create_reset_curnb(eval_ctx_t *ctx);
int eval_has_nb_or_res(eval_ctx_t *ctx);

/*
** eval/eval_branch.c
*/
eval_branch_t *eval_branch_create(int op, number_t *nb, int priority);
void eval_branch_free(eval_branch_t *branch);

/*
** eval/eval_branch_insert.c
*/
void eval_branch_insert_rightnb(eval_ctx_t *ctx);
void eval_branch_insert_op(bistro_t *bistro, eval_branch_t **branch,
	eval_insert_op_t *insert_op);

/*
** eval/eval_branch_set.c
*/
void eval_branch_set_left(eval_branch_t *parent, eval_branch_t *to_left);
void eval_branch_set_right(eval_branch_t *parent, eval_branch_t *to_right);

/*
** eval/eval_branch_calc.c
*/
void eval_branch_calc(bistro_t *bistro, eval_branch_t **cur_branch,
	eval_branch_t *calc_branch);

#endif