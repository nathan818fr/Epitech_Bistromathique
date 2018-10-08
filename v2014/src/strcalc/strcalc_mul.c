/*
** strcalc_add.c for strcalc in /home/poirie_n/repo/B1/C_Prog_Elem/Bistromathique/strcalc
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Sun Oct 26 16:56:15 2014 Nathan Poirier
** Last update Sun Nov  9 18:36:52 2014 Nathan
*/

#include "bistro.h"

void	strcalc_mul_char(t_strnb *nb1, t_strnb *nb2, t_strnb *result,
			 t_def *def)
{
  int	r;

  r = result->str[def->var->i + def->var->j];
  r = r  + (int)nb1->str[def->var->j] * (int)nb2->str[def->var->i];
  if (r >= def->lenofbase)
    {
      result->str[def->var->i + def->var->j + 1] = r / def->lenofbase;
      result->strlen = def->var->i + def->var->j + 2;
    }
  result->str[def->var->i + def->var->j] = r % def->lenofbase;
  if (result->strlen < def->var->i + def->var->j + 1)
    result->strlen = def->var->i + def->var->j + 1;
}

char	strcalc_mul_negcheck(t_strnb *nb1, t_strnb *nb2)
{
  char	neg;

  neg = (nb1->is_neg != nb2->is_neg);
  nb2->is_neg = 0;
  nb1->is_neg = 0;
  return (neg);
}

t_strnb		*strcalc_mul2(t_strnb *result, t_strnb *tmp, int len,
			      t_def *def)
{
  t_strnb       *nresult;

  nresult = strcalc_add(result, tmp, def);
  strcalc_strnb_free(result);
  strcalc_reset_strnb(tmp, len);
  return (nresult);
}

t_strnb		*strcalc_mul(t_strnb *nb1, t_strnb *nb2, t_def *def)
{
  t_strnb	*result;
  t_strnb	*tmp;
  char		is_neg;
  int		len;

  is_neg = strcalc_mul_negcheck(nb1, nb2);
  tmp = strcalc_create_strnb((len = nb1->strlen + nb2->strlen + 1));
  if ((result = strcalc_create_strnb(len)) == NULL || tmp == NULL)
    return (NULL);
  if (strcalc_strnb_cmp(nb1, nb2, def) > 0)
    strcalc_swap(&nb1, &nb2);
  def->var->i = -1;
  while ((def->var->i = def->var->i + 1) < nb2->strlen)
    {
      def->var->j = -1;
      while ((def->var->j = def->var->j + 1) < nb1->strlen)
	strcalc_mul_char(nb1, nb2, tmp, def);
      result = strcalc_mul2(result, tmp, len, def);
    }
  result->is_neg = is_neg;
  strcalc_strnb_free(tmp);
  return (result);
}
