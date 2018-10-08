#include <stdlib.h>
#include "bistro.h"
#include "bistro_number.h"
#include "bistro_utils.h"

number_t *number_create(size_t len)
{
	number_t *nb;

	if (len < 1)
		len = 1;
	nb = bistro_malloc(sizeof(number_t));
	my_memset(nb, 0, sizeof(number_t));
	nb->len = len;
	nb->str = bistro_malloc(sizeof(nbchar_t) * len);
	my_memset(nb->str, 0, sizeof(nbchar_t) * len);
	return nb;
}

number_t *number_dup(number_t *nb)
{
	number_t *new = number_create(nb->len);
	size_t i = 0;

	while (i < nb->len) {
		new->str[i] = nb->str[i];
		i = i + 1;
	}
	new->is_neg = nb->is_neg;
	return (new);
}

number_t *number_dup_with_len(number_t *nb, size_t len)
{
	number_t *new = number_create(len);
	size_t i = 0;

	while (i < nb->len && i < new->len) {
		new->str[i] = nb->str[i];
		i = i + 1;
	}
	new->is_neg = nb->is_neg;
	number_fix(new);
	return (new);
}

void number_free(number_t *nb)
{
	if (nb) {
		if (nb->str)
			free(nb->str);
		free(nb);
	}
}

number_t *number_fix(number_t *nb)
{
	while (nb->len > 1 && nb->str[nb->len - 1] == 0) {
		nb->len = nb->len - 1;
	}
	if (nb->is_neg && nb->len == 1 && nb->str[nb->len - 1] == 0)
		nb->is_neg = 0;
	return (nb);
}
