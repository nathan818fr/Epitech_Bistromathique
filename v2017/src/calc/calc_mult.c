#include <stdio.h>
#include "bistro_calc.h"
#include "bistro_utils.h"

void calc_mult_digits(calc_t *calc, calc_t *result, size_t i, size_t j)
{
	int c1 = 0;
	int c2 = 0;

	if (j < calc->nbr1->len)
		c1 = calc->nbr1->str[j];
	if (i < calc->nbr2->len)
		c2 = calc->nbr2->str[i];
	c1 = c1 * c2 + result->nbr1->str[j + i];
	if (c1 >= calc->bistro->base_len)
		result->nbr1->str[j + i + 1] =
			(nbchar_t) (c1 / calc->bistro->base_len);
	result->nbr1->str[j + i] = (nbchar_t) (c1 % calc->bistro->base_len);
}

void calc_mult_add(calc_t *calc, calc_t *result)
{
	size_t i = 0;
	size_t j = 0;

	while (i < calc->nbr2->len) {
		j = 0;
		while (j < calc->nbr1->len) {
			calc_mult_digits(calc, result, i, j);
			j = j + 1;
		}
		calc_add_numbers(result);
		number_free(result->nbr2);
		result->nbr2 = result->result;
		result->result = NULL;
		my_memset(result->nbr1->str, 0, result->nbr1->len);
		i = i + 1;
	}
	number_free(result->nbr1);
}

void calc_mult_numbers(calc_t *calc)
{
	calc_t result;
	size_t max_len = calc->nbr1->len + calc->nbr2->len;

	result.nbr1 = number_create(max_len);
	result.nbr2 = number_create(max_len);
	result.bistro = calc->bistro;
	if (calc_cmp_numbers(calc) > 0)
		calc_swap_numbers(calc);
	calc_mult_add(calc, &result);
	calc->result = result.nbr2;
	if (calc->nbr1->is_neg != calc->nbr2->is_neg)
		calc->result->is_neg = 1;
}

void calc_mult(calc_t *calc)
{
	calc_mult_numbers(calc);
}