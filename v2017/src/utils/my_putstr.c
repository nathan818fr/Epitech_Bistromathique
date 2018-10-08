#include <stdlib.h>
#include <unistd.h>
#include "bistro_utils.h"

void my_putstr_to(int fd, char const *str)
{
	write(fd, str, my_strlen(str));
}

void my_putstr(char const *str)
{
	my_putstr_to(STDOUT_FILENO, str);
}

void my_puterr(char const *str)
{
	my_putstr_to(STDERR_FILENO, str);
}
