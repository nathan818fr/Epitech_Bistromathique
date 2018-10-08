#include "bistro_number.h"
#include "bistro_utils.h"
#include "bistro_calc.h"

number_t *calc(number_t *nbr1, number_t *nbr2, int op, bistro_t *bistro)
{
	calc_t calc;

	calc.nbr1 = nbr1;
	calc.nbr2 = nbr2;
	calc.bistro = bistro;
	if (op == OP_PLUS_IDX)
		calc_add(&calc);
	else if (op == OP_SUB_IDX || op == OP_NEG_IDX)
		calc_sub(&calc);
	else if (op == OP_MULT_IDX)
		calc_mult(&calc);
	else if (op == OP_DIV_IDX)
		calc_div(&calc);
	else if (op == OP_MOD_IDX)
		calc_mod(&calc);
	else
		BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "unknown op");
	return (number_fix(calc.result));
}