#include <stdlib.h>
#include "bistro_utils.h"

void *my_memset(void *a, int c, size_t size)
{
	char *str = (char *) a;
	size_t i = 0;

	while (i < size) {
		str[i] = (char) c;
		i = i + 1;
	}
	return (a);
}