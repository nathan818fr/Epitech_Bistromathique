/*
** my_get_big_nbr.c for strcalc in /home/poirie-n/blinux/poirie_n/repo/B1/C_Prog_Elem/Bistromathique/src/utils
** 
** Made by Nathan
** Login   <poirie-n@epitech.net>
** 
** Started on  Sun Nov  9 17:16:11 2014 Nathan
** Last update Sun Nov  9 17:29:43 2014 Nathan
*/

#include "my.h"
#include "my_utils.h"

unsigned int	my_get_big_nbr(char *str)
{
  int		i;
  int		pow;
  unsigned int	pnb;
  unsigned int	nb;

  i = my_strlen(str);
  if (i > 10)
    return (0);
  nb = 0;
  pow = 1;
  while (i > 0)
    {
      i = i - 1;
      if (str[i] < '0' || str[i] > '9')
	return (0);
      pnb = nb;
      nb = nb + (str[i] - '0') * pow;
      pow = pow * 10;
      if (nb < pnb)
	return (0);
    }
  return (nb);
}
