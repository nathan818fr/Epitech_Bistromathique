/*
** strcalc_add.c for strcalc in /home/poirie_n/repo/B1/C_Prog_Elem/Bistromathique/strcalc
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Sun Oct 26 16:56:15 2014 Nathan Poirier
** Last update Sun Nov  9 18:36:35 2014 Nathan
*/

#include "bistro.h"

void	strcalc_add_char(t_strnb *nb1, t_strnb *nb2, t_strnb *result,
			 t_def *def)
{
  int	n1;
  int	n2;

  n1 = 0;
  n2 = 0;
  if (def->var->k < nb1->strlen)
    n1 = nb1->str[def->var->k];
  if (def->var->k < nb2->strlen)
    n2 = nb2->str[def->var->k];
  n1 = result->str[def->var->k] + n1 + n2;
  if (n1 >= def->lenofbase)
    {
      result->str[def->var->k + 1] = n1 / def->lenofbase;
      result->strlen = def->var->k + 2;
    }
  result->str[def->var->k] = n1 % def->lenofbase;
  if (result->strlen < def->var->k + 1)
    result->strlen = def->var->k + 1;
}

t_strnb		*strcalc_add(t_strnb *nb1, t_strnb *nb2, t_def *def)
{
  t_strnb	*result;
  int		len;

  if (nb1->is_neg && !nb2->is_neg && !(nb1->is_neg = 0))
    return (strcalc_sub(nb2, nb1, def));
  else if (nb2->is_neg && !nb1->is_neg && !(nb2->is_neg = 0))
    return (strcalc_sub(nb1, nb2, def));
  len = strcalc_max(nb1->strlen, nb2->strlen);
  result = strcalc_create_strnb(len);
  if (result == NULL)
    return (NULL);
  def->var->k = 0;
  while (def->var->k < nb1->strlen || def->var->k < nb2->strlen)
    {
      strcalc_add_char(nb1, nb2, result, def);
      def->var->k = def->var->k + 1;
    }
  if (nb1->is_neg && nb2->is_neg)
    result->is_neg = 1;
  return (result);
}
