/*
** strcalc_sub.c for strcalc in /home/poirie_n/repo/B1/C_Prog_Elem/Bistromathique/strcalc
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Mon Oct 27 17:14:48 2014 Nathan Poirier
** Last update Sun Nov  9 17:58:56 2014 timothy greil
*/

#include <bistro.h>

void	strcalc_sub_char(t_strnb *nb1, t_strnb *nb2,
			 t_strnb *result, t_def *def)
{
  int	n1;
  int	n2;

  n1 = 0;
  n2 = 0;
  if (def->var->k < nb1->strlen)
    n1 = nb1->str[def->var->k];
  if (def->var->k < nb2->strlen)
    n2 = nb2->str[def->var->k];
  n1 = n1 - n2 - result->str[def->var->k];
  if (n1 < 0)
    {
      result->str[def->var->k + 1] = 1;
      n1 = def->lenofbase + n1;
    }
  result->str[def->var->k] = n1 % def->lenofbase;
  result->strlen = def->var->k + 1;
}

t_strnb		*strcalc_sub(t_strnb *nb1, t_strnb *nb2, t_def *def)
{
  t_strnb	*result;
  int		len;

  if (!nb1->is_neg && nb2->is_neg && (nb2->is_neg = 0) == 0)
    return (strcalc_add(nb1, nb2, def));
  if (nb1->is_neg && !nb2->is_neg && (nb2->is_neg = 1) == 1)
    return (strcalc_add(nb1, nb2, def));
  len = strcalc_max(nb1->strlen, nb2->strlen);
  if ((result = strcalc_create_strnb(len)) == NULL)
    return (NULL);
  if (strcalc_strnb_cmp(nb1, nb2, def) > 0)
    {
      strcalc_swap(&nb1, &nb2);
      result->is_neg = 1;
    }
  def->var->k = -1;
  while ((def->var->k = def->var->k + 1) < nb1->strlen ||
	 def->var->k < nb2->strlen)
    strcalc_sub_char(nb1, nb2, result, def);
  if (nb1->is_neg && nb2->is_neg)
    result->is_neg = (!result->is_neg);
  return (result);
}
