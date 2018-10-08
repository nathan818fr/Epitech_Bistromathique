#include <stdlib.h>
#include <unistd.h>
#include "bistro_utils.h"

void my_putnbr_s(int fd, long nb)
{
	char c;

	if (nb <= -10)
		my_putnbr_s(fd, nb / 10);
	c = (char) ('0' - (nb % 10));
	write(fd, &c, 1);
}

void my_putnbr(int fd, long nb)
{
	if (nb < 0) {
		my_putstr_to(fd, "-");
		my_putnbr_s(fd, nb);
	} else
		my_putnbr_s(fd, -nb);
}
