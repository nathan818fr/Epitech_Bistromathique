#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "bistro.h"
#include "bistro_eval.h"
#include "bistro_utils.h"

int main(int ac, char **av)
{
	bistro_t bistro;
	char *result;

	if (ac != 4) {
		my_putstr("Usage: ");
		my_putstr(av[0]);
		my_putstr(" base ops \"()+-*/%\" exp_len\n");
		return (EXIT_USAGE);
	}
	my_memset(&bistro, 0, sizeof(bistro_t));
	bistro.base = get_base(&bistro, av[1]);
	bistro.ops = get_ops(av[2]);
	if (bistro_char_matching(bistro.base, bistro.ops))
		BISTRO_ERROR(EXIT_OPS, SYNTAX_ERROR_MSG,
                             "same char in both base and ops");
	bistro.expr_len = bistro_get_nbr(av[3]);
	bistro.expr = get_expr(bistro.expr_len);
	result = eval(&bistro);
	my_putstr(result);
	free(result);
	free((void *) bistro.expr);
	return (EXIT_SUCCESS);
}

const char *get_base(bistro_t *bistro, char const *base)
{
	bistro->base_len = (int) my_strlen(base);
	if (bistro->base_len < 2)
		BISTRO_ERROR(EXIT_BASE, SYNTAX_ERROR_MSG, "too short base");
	else if (bistro_char_is_repeating(base))
		BISTRO_ERROR(EXIT_BASE, SYNTAX_ERROR_MSG,
			     "char repeat in base");
	return (base);
}

char *get_expr(size_t size)
{
	char *expr;
	size_t cursize = 0;
	ssize_t rlen = 0;

	if (size <= 0)
		BISTRO_ERROR(EXIT_SIZE_NEG, SYNTAX_ERROR_MSG, "expr size neg");
	expr = bistro_malloc(size);
	while (cursize < size) {
		rlen = read(STDIN_FILENO, expr + cursize,
			MY_MIN(BISTRO_READ_CHUNKS, size - cursize));
		if (rlen <= 0)
			break;
		cursize += rlen;
	}
	if (rlen == -1)
		BISTRO_ERROR(EXIT_READ, ERROR_MSG, "read error");
	if (cursize != size)
		BISTRO_ERROR(EXIT_READ, ERROR_MSG, "bad read size");
	return (expr);
}

const char *get_ops(char const *ops)
{
	if (my_strlen(ops) != OPS_SIZE)
		BISTRO_ERROR(EXIT_OPS, SYNTAX_ERROR_MSG, "bad ops len");
	else if (bistro_char_is_repeating(ops))
		BISTRO_ERROR(EXIT_OPS, SYNTAX_ERROR_MSG, "char repeat in ops");
	return (ops);
}
