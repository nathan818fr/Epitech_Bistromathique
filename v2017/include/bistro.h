#ifndef BISTRO_H_
#define BISTRO_H_

#include <stdlib.h>

#define OP_NBR	(-1)
#define OPS_SIZE 7

#define OP_OPEN_PARENT_IDX	0
#define OP_CLOSE_PARENT_IDX	1
#define OP_PLUS_IDX		2
#define OP_SUB_IDX		3
#define OP_NEG_IDX		3
#define OP_MULT_IDX		4
#define OP_DIV_IDX		5
#define OP_MOD_IDX		6


#define EXIT_USAGE	84
#define EXIT_BASE	84
#define EXIT_SIZE_NEG	84
#define EXIT_MALLOC	84
#define EXIT_READ	84
#define EXIT_OPS	84

#define SYNTAX_ERROR_MSG	"syntax error"
#define ERROR_MSG		"error"

#define BISTRO_READ_CHUNKS 8192

typedef struct bistro_s {
	char const *expr;
	size_t expr_len;
	char const *base;
	int base_len;
	char const *ops;
} bistro_t;

/*
** main.c
*/
const char *get_base(bistro_t *, char const *);
const char *get_ops(char const *);
char *get_expr(size_t);

#endif