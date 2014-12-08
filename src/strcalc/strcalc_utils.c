/*
** strcalc_utils.c for strcalc in /home/poirie_n/repo/B1/C_Prog_Elem/Bistromathique/strcalc
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Mon Oct 27 21:10:06 2014 Nathan Poirier
** Last update Wed Nov  5 15:59:29 2014 Nathan Poirier
*/

#include "bistro.h"

int	strcalc_strnb_is_zero(t_strnb *nb)
{
  if (nb->strlen == 1 && nb->str[0] == 0)
    return (1);
  return (0);
}

int     strcalc_strnb_cmp(t_strnb *nb1, t_strnb *nb2, t_def *def)
{
  int	i;
  int	r;

  def->base = def->base;
  if (nb1->is_neg && !nb2->is_neg)
    return (1);
  if (nb1->strlen != nb2->strlen)
    return (nb2->strlen - nb1->strlen);
  i = nb1->strlen;
  while (i > 0)
    {
      i = i - 1;
      r = nb2->str[i] - nb1->str[i];
      if (r != 0)
	return (r);
    }
  return (0);
}

void            strcalc_swap(t_strnb **nb1, t_strnb **nb2)
{
  t_strnb       *swap;

  swap = *nb1;
  *nb1 = *nb2;
  *nb2 = swap;
}

int	strcalc_max(int a, int b)
{
  if (b > a)
    return (b);
  return (a);
}

void	strcalc_strnb_cpy(t_strnb *src, t_strnb *dst)
{
  int	i;

  i = 0;
  while (i < src->strlen)
    {
      dst->str[i] = src->str[i];
      i = i + 1;
    }
  dst->strlen = src->strlen;
}
