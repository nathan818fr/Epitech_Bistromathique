/*
** strcalc_utils2.c for strcalc in /home/poirie_n/repo/B1/C_Prog_Elem/Bistromathique
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Wed Nov  5 14:25:03 2014 Nathan Poirier
** Last update Sat Nov  8 14:12:45 2014 Nathan Poirier
*/

#include "bistro.h"

void	strcalc_strnb_baseup(t_strnb *nb)
{
  int	i;

  i = nb->strlen;
  while (i > 0)
    {
      i = i - 1;
      nb->str[i + 1] = nb->str[i];
    }
  nb->str[0] = 0;
  nb->strlen = nb->strlen + 1;
}

void    strcalc_strnb_basedown(t_strnb *nb)
{
  int i;

  nb->strlen = nb->strlen - 1;
  i = 0;
  while (i < nb->strlen)
    {
      nb->str[i] = nb->str[i + 1];
      i = i + 1;
    }
  nb->str[i] = 0;
}

void	strcalc_strnb_updatelen(t_strnb *nb)
{
  while (nb->strlen > 1 && nb->str[nb->strlen - 1] == 0)
    {
      nb->strlen = nb->strlen - 1;
    }
}

int     strcalc_strnb_is_zero2(t_strnb *nb)
{
  int	i;

  i = nb->strlen;
  while (i > 0)
    {
      i = i - 1;
      if (nb->str[i] != 0)
	return (0);
    }
  return (1);
}

int	strcalc_strnb_free(t_strnb *nb)
{
  if (nb != NULL)
    {
      if (nb->str != NULL)
	free(nb->str);
      free(nb);
    }
  return (1);
}
