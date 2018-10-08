#include <stdlib.h>
#include "bistro.h"
#include "bistro_number.h"
#include "bistro_utils.h"

int number_char_val(bistro_t *bistro, char c)
{
	int i = 0;

	while (i < bistro->base_len) {
		if (bistro->base[i] == c)
			return (i);
		i = i + 1;
	}
	return (-1);
}

char *number_to_string(bistro_t *bistro, number_t *nb)
{
	char *str;
	size_t i = 0;
	size_t j = 0;

	str = bistro_malloc(
		sizeof(char) * (nb->len + (nb->is_neg ? 1 : 0)) + 1);
	if (nb->is_neg) {
		str[i] = '-';
		i = i + 1;
	}
	while (j < nb->len) {
		str[i] = bistro->base[nb->str[nb->len - j - 1]];
		i = i + 1;
		j = j + 1;
	}
	str[i] = '\0';
	return (str);
}

void number_base_inc(number_t *nb)
{
	size_t i = nb->len;

	nb->len = nb->len + 1;
	while (i > 0) {
		nb->str[i] = nb->str[i - 1];
		i = i - 1;
	}
	nb->str[0] = 0;
}

void number_base_dec(number_t *nb)
{
	size_t i = 0;

	while (i < nb->len - 1) {
		nb->str[i] = nb->str[i + 1];
		i = i + 1;
	}
	nb->str[i] = 0;
	nb->len = nb->len - 1;
}
