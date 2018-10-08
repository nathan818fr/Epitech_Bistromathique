#include "bistro_calc.h"
#include "bistro_utils.h"

void calc_mod_numbers(calc_t *calc)
{
	number_t *nbr1;
	number_t *res;

	nbr1 = calc->nbr1;
	calc_div(calc);
	res = number_fix(calc->result);
	calc->nbr1 = calc->nbr2;
	calc->nbr2 = res;
	calc_mult(calc);
	number_free(res);
	res = number_fix(calc->result);
	calc->nbr1 = nbr1;
	calc->nbr2 = calc->result;
	calc_sub(calc);
	number_free(res);
	res = number_fix(calc->result);
	calc->result = res;
}

void calc_mod(calc_t *calc)
{
	char is_neg;

	is_neg = calc->nbr1->is_neg;
	if (calc->nbr2->len == 1 && calc->nbr2->str[0] == 0)
		BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "mod by 0");
	else if (calc->nbr2->len == 1 && calc->nbr2->str[0] == 1)
		calc->result = number_create(1);
	else if (calc_cmp_numbers(calc) > 0)
		calc->result = number_dup(calc->nbr1);
	else {
		calc->nbr1->is_neg = 0;
		calc->nbr2->is_neg = 0;
		calc_mod_numbers(calc);
	}
	calc->result->is_neg = is_neg;
}