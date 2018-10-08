#include <stdio.h>
#include "bistro_calc.h"
#include "bistro_utils.h"

void calc_add_digits(calc_t *calc, size_t i)
{
	int c1 = 0;
	int c2 = 0;

	if (i < calc->nbr1->len)
		c1 = calc->nbr1->str[i];
	if (i < calc->nbr2->len)
		c2 = calc->nbr2->str[i];
	c1 = calc->result->str[i] + c1 + c2;
	if (c1 >= calc->bistro->base_len)
		calc->result->str[i + 1] =
			(nbchar_t) (c1 / calc->bistro->base_len);
	calc->result->str[i] = (nbchar_t) (c1 % calc->bistro->base_len);
}

void calc_add_numbers(calc_t *calc)
{
	size_t i = 0;
	size_t max_len = MY_MAX(calc->nbr1->len, calc->nbr2->len);
	calc->result = number_create(max_len + 1);

	while (i < max_len) {
		calc_add_digits(calc, i);
		i = i + 1;
	}
	if (calc->nbr1->is_neg && calc->nbr2->is_neg)
		calc->result->is_neg = 1;
}

void calc_add(calc_t *calc)
{
	if (calc->nbr1->is_neg && !calc->nbr2->is_neg) {
		calc->nbr1->is_neg = 0;
		calc_swap_numbers(calc);
		calc_sub(calc);
	} else if (!calc->nbr1->is_neg && calc->nbr2->is_neg) {
		calc->nbr2->is_neg = 0;
		calc_sub(calc);
	} else
		calc_add_numbers(calc);
}
