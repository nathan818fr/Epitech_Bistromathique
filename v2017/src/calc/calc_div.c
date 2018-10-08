#include "bistro_utils.h"
#include "bistro_calc.h"

void calc_div_subs(calc_t *dividend, calc_t *quotient)
{
	while (calc_cmp_numbers(dividend) <= 0) {
		calc_sub_numbers(dividend);
		number_fix(dividend->result);
		number_free(dividend->nbr1);
		dividend->nbr1 = dividend->result;
		dividend->result = NULL;
		calc_add_numbers(quotient);
		number_fix(quotient->result);
		number_free(quotient->nbr1);
		quotient->nbr1 = quotient->result;
		quotient->result = NULL;
	}
}

void calc_div_opti_subs(calc_t *dividend, calc_t *quotient)
{
	while (calc_cmp_numbers(dividend) <= 0) {
		number_base_inc(dividend->nbr2);
		number_base_inc(quotient->nbr2);
	}
	while (quotient->nbr2->len > 1) {
		number_base_dec(dividend->nbr2);
		number_base_dec(quotient->nbr2);
		calc_div_subs(dividend, quotient);
	}
}

void calc_div_numbers(calc_t *calc)
{
	calc_t dividend;
	calc_t quotient;

	dividend.bistro = calc->bistro;
	dividend.nbr1 = number_dup(calc->nbr1);
	dividend.nbr2 = number_dup_with_len(calc->nbr2, calc->nbr1->len + 1);
	quotient.bistro = calc->bistro;
	quotient.nbr1 = number_create(1);
	quotient.nbr2 = number_create(calc->nbr1->len + 1);
	quotient.nbr2->len = 1;
	quotient.nbr2->str[0] = 1;
	calc_div_opti_subs(&dividend, &quotient);
	calc->result = quotient.nbr1;
	number_free(dividend.nbr1);
	number_free(dividend.nbr2);
	number_free(quotient.nbr2);
}

void calc_div(calc_t *calc)
{
	if (calc->nbr2->len == 1 && calc->nbr2->str[0] == 0)
		BISTRO_ERROR(EXIT_USAGE, SYNTAX_ERROR_MSG, "div by 0");
	else if (calc->nbr2->len == 1 && calc->nbr2->str[0] == 1)
		calc->result = number_dup(calc->nbr1);
	else if (calc_cmp_numbers(calc) > 0)
		calc->result = number_create(1);
	else
		calc_div_numbers(calc);
	calc->result->is_neg = (calc->nbr1->is_neg != calc->nbr2->is_neg);
}
