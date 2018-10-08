#include <stdint.h>
#include "bistro_utils.h"

size_t bistro_get_nbr_maxlen()
{
	size_t l = 0;
	size_t max = SIZE_MAX;

	while (max > 0) {
		l = l + 1;
		max = max / (size_t) 10;
	}
	return (l);
}

size_t bistro_get_nbr(char *str)
{
	size_t i = 0;
	size_t pow = 1;
	size_t nbr = 0;
	size_t max_nbr = 0;

	i = my_strlen(str);
	if (i > bistro_get_nbr_maxlen())
		return (0);
	while (i > 0) {
		i = i - 1;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		max_nbr = nbr;
		nbr = nbr + (str[i] - '0') * pow;
		if (nbr < max_nbr)
			return (0);
		pow = pow * 10;
	}
	return (nbr);
}
