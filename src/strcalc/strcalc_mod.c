/*
** strcalc_mul.c for calc the mul on str  in /home/greil_t/rendu/Bistromathique/strcalc
** 
** Made by timothy greil
** Login   <greil_t@epitech.net>
** 
** Started on  Tue Oct 28 14:00:03 2014 timothy greil
** Last update Sat Nov  8 13:39:44 2014 Nathan Poirier
*/

#include "bistro.h"

t_strnb		*strcalc_mod(t_strnb *nb1, t_strnb *nb2, t_def *def)
{
  t_strnb	*res1;
  t_strnb	*res2;
  char		is_neg;

  if (strcalc_strnb_is_zero(nb2))
    return (my_error(RUNTIME_ERROR_MSG, RUNTIME_ERROR_MODZERO));
  if (nb1->is_neg == 1)
    is_neg = 1;
  else
    is_neg = 0;
  nb1->is_neg = 0;
  nb2->is_neg = 0;
  if (strcalc_strnb_cmp(nb1, nb2, def) > 0)
    {
      nb1->is_neg = is_neg;
      return (nb1);
    }
  res1 = strcalc_div(nb1, nb2, def);
  res2 = strcalc_mul(nb2, res1, def);
  strcalc_strnb_free(res1);
  res1 = strcalc_sub(nb1, res2, def);
  strcalc_strnb_free(res2);
  res1->is_neg = is_neg;
  return (res1);
}
