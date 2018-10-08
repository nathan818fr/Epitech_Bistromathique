/*
** strcalc_mul.c for calc the mul on str  in /home/greil_t/rendu/Bistromathique/strcalc
** 
** Made by timothy greil
** Login   <greil_t@epitech.net>
** 
** Started on  Tue Oct 28 14:00:03 2014 timothy greil
** Last update Sun Nov  9 18:05:03 2014 timothy greil
*/

#include <bistro.h>

t_strnb		*strcalc_div_unit(int lv)
{
  t_strnb       *unit;

  unit = strcalc_create_strnb(lv);
  unit->strlen = lv + 1;
  unit->str[lv] = 1;
  return (unit);
}

void	strcalc_div_calc2(t_strnb **nb1, t_strnb *tmp,
			  t_strnb **result, t_def *def)
{
  int		e;
  t_strnb	*prev;
  t_strnb	*r;
  t_strnb	*unit;

  unit = strcalc_div_unit(def->var->i);
  e = 1;
  while (e)
    {
      strcalc_strnb_updatelen((r = strcalc_sub(*nb1, tmp, def)));
      if (!r->is_neg)
	{
	  prev = *result;
	  *result = strcalc_add(*result, unit, def);
	  strcalc_strnb_free(prev);
	  e = (strcalc_strnb_cmp(r, tmp, def) <= 0);
	  if (def->var->can_free)
	    strcalc_strnb_free(*nb1);
	  *nb1 = r;
	  def->var->can_free = 1;
	}
      else if (strcalc_strnb_free(r))
	e = 0;
    }
  strcalc_strnb_free(unit);
}

t_strnb		*strcalc_div_calc(t_strnb *nb1, t_strnb *tmp,
				  t_strnb *result, t_def *def)
{
  t_strnb	*prev;

  prev = result;
  prev = prev;
  def->var->i = 0;
  def->var->can_free = 0;
  while (strcalc_strnb_cmp(nb1, tmp, def) <= 0)
    {
      strcalc_strnb_baseup(tmp);
      def->var->i = def->var->i + 1;
    }
  while ((def->var->i = def->var->i - 1) > -1)
    {
      strcalc_strnb_basedown(tmp);
      strcalc_div_calc2(&nb1, tmp, &result, def);
    }
  if (def->var->can_free)
    strcalc_strnb_free(nb1);
  return (result);
}

t_strnb		*strcalc_div(t_strnb *nb1, t_strnb *nb2, t_def *def)
{
  t_strnb	*result;
  t_strnb	*tmp;
  char		is_neg;

  if (strcalc_strnb_is_zero(nb2))
    return (my_error(RUNTIME_ERROR_MSG, RUNTIME_ERROR_DIVZERO));
  is_neg = (nb1->is_neg != nb2->is_neg);
  nb1->is_neg = 0;
  nb2->is_neg = 0;
  if (strcalc_strnb_cmp(nb1, nb2, def) > 0)
    {
      if ((tmp = strcalc_create_strnb(0)) == NULL)
	return (NULL);
      tmp->str[0] = def->base[0];
      tmp->str[1] = '\0';
      return (tmp);
    }
  result = strcalc_create_strnb(nb1->strlen);
  tmp = strcalc_create_strnb(nb1->strlen + 2);
  strcalc_strnb_cpy(nb2, tmp);
  result = strcalc_div_calc(nb1, tmp, result, def);
  strcalc_strnb_free(tmp);
  result->is_neg = is_neg;
  return (result);
}
