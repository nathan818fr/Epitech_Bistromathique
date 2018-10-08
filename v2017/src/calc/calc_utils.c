#include <stdio.h>
#include "bistro_calc.h"

void calc_swap_numbers(calc_t *calc)
{
	number_t *nbr = calc->nbr1;
	calc->nbr1 = calc->nbr2;
	calc->nbr2 = nbr;
}

int calc_cmp_numbers(calc_t *calc)
{
	size_t i = calc->nbr1->len;
	size_t j = calc->nbr2->len;
	int k = 0;

	if (i != j)
		return (int) (j - i);
	while (i > 0) {
		i = i - 1;
		k = calc->nbr2->str[i] - calc->nbr1->str[i];
		if (k != 0)
			return (k);
	}
	return (0);
}