#include <stdlib.h>
#include "bistro_utils.h"

size_t my_strlen(char const *str)
{
	size_t i = 0;

	while (str[i] != '\0') {
		i = i + 1;
	}
	return (i);
}