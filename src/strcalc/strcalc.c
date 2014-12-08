/*
** strcalc.c for strcalc in /home/poirie_n/repo/B1/C_Prog_Elem/Bistromathique/strcalc
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Sun Oct 26 03:03:45 2014 Nathan Poirier
** Last update Fri Nov  7 15:15:18 2014 Nathan Poirier
*/

#include "bistro.h"

t_strnb		*strcalc_create_strnb(int str_len)
{
  t_strnb	*strnb;

  if ((strnb = malloc(sizeof(t_strnb))) == NULL)
    return (my_error(RUNTIME_ERROR_MSG, RUNTIME_ERROR_MEMORY));
  if ((strnb->str = malloc(str_len + 2)) == NULL)
    return (my_error(RUNTIME_ERROR_MSG, RUNTIME_ERROR_MEMORY));
  strcalc_reset_strnb(strnb, str_len);
  return (strnb);
}

void	strcalc_reset_strnb(t_strnb *strnb, int len)
{
  int	i;

  i = 0;
  while (i < len + 1)
    {
      strnb->str[i] = 0;
      i = i + 1;
    }
  strnb->strlen = 0;
  strnb->is_neg = 0;
}

t_strnb		*strcalc_str_to_strnb(char *str, t_def *def)
{
  t_strnb	*strnb;
  int		len;
  int		i;
  int		p;

  len = my_strlen(str);
  i = len;
  p = 0;
  if ((strnb = strcalc_create_strnb(len)) == NULL)
    return (NULL);
  while (i > 0)
    {
      i = i - 1;
      if (str[i] == def->structure[OP_SUB_IDX])
	strnb->is_neg = 1;
      else
	{
	  strnb->str[p] = from_base(str[i], def);
	  p = p + 1;
	}
    }
  strnb->str[p] = '\0';
  strnb->strlen = p;
  return (strnb);
}

char	*strcalc_strnb_to_str(t_strnb *strnb, t_def *def)
{
  char	*str;
  int	i;
  int	p;

  if (strnb == NULL)
    return (NULL);
  if (strnb->is_neg && strcalc_strnb_is_zero2(strnb))
    strnb->is_neg = 0;
  if ((str = malloc(strnb->strlen + strnb->is_neg + 2)) == NULL)
    return (my_error(RUNTIME_ERROR_MSG, RUNTIME_ERROR_MEMORY));
  if (strnb->is_neg)
    str[0] = def->structure[OP_SUB_IDX];
  i = strnb->strlen;
  p = 0;
  while ((i = i - 1) >= 0)
    {
      if (p || strnb->str[i] != 0)
	str[((p = p + 1) - 1) + strnb->is_neg] = to_base(strnb->str[i], def);
    }
  if (p == 0 && (str[p + strnb->is_neg] = def->base[0]) == def->base[0])
    p = p + 1;
  str[p + strnb->is_neg] = '\0';
  return (str);
}

char	*strcalc(char *n1, char *n2, char op, t_def *def)
{
  char		*str;
  t_strnb	*res;
  t_strnb       *nb1;
  t_strnb       *nb2;

  if ((nb1 = strcalc_str_to_strnb(n1, def)) == NULL ||
      (nb2 = strcalc_str_to_strnb(n2, def)) == NULL)
    return (NULL);
  res = NULL;
  if (op == def->structure[OP_PLUS_IDX])
    res = strcalc_add(nb1, nb2, def);
  else if (op == def->structure[OP_SUB_IDX])
    res = strcalc_sub(nb1, nb2, def);
  else if (op == def->structure[OP_MULT_IDX])
    res = strcalc_mul(nb1, nb2, def);
  else if (op == def->structure[OP_DIV_IDX])
    res = strcalc_div(nb1, nb2, def);
  else if (op == def->structure[OP_MOD_IDX])
    res = strcalc_mod(nb1, nb2, def);
  str = strcalc_strnb_to_str(res, def);
  if (res != NULL && res != nb1)
    strcalc_strnb_free(res);
  strcalc_strnb_free(nb1);
  strcalc_strnb_free(nb2);
  return (str);
}
