/*
** expr_str_check.c for bistro in /home/poirie_n/repo/B1/C_Prog_Elem/Bistromathique/btree
**  
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Sun Oct 26 17:59:12 2014 Nathan Poirier
** Last update Fri Nov  7 13:46:14 2014 Nathan Poirier
*/

#include "bistro.h"

int	check_number(t_def *def, int i)
{
  int	n;

  n = 0;
  while (def->base[n] != def->str[i] && def->base[n] != '\0')
    n = n + 1;
  if (def->base[n] == '\0')
    return (0);
  if (def->str[i + 1] == def->structure[OP_OPEN_PARENT_IDX])
    return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_BRACKET5));
  return (0);
}

int	check_twobase(t_def *def)
{
  int	first;
  int	second;

  first = 0;
  if (my_strlen(def->structure) != 7)
    {
      return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_OPLEN));
    }
  while (def->base[first] != '\0')
    {
      second = 0;
      while (def->structure[second] != '\0')
	{
	  if (def->base[first] == def->structure[second])
	    return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_BASEOP_REP));
	  second = second + 1;
	}
      first = first + 1;
    }
  return (0);
}

int	check_char_rep(char *str, char type)
{
  int	n;
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      n = 0;
      while (str[n] != '\0')
	{
	  if (n != i && str[n] == str[i])
	    {
	      if (type == 0)
		return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_BASE_REP));
	      else
		return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_OP_REP));
	    }
	  n = n + 1;
	}
      i = i + 1;
    }
  return (0);
}

int	next_check(t_def *def, int i)
{
  if (is_valid_structure_or_base(def, i) != 0)
    return (1);
  if ((def->str[i] == def->structure[OP_OPEN_PARENT_IDX] ||
       def->str[i] == def->structure[OP_CLOSE_PARENT_IDX]) &&
      check_bracket(def, i) != 0)
    return (1);
  if (check_operator(def, i) != 0)
    return (1);
  if (check_number(def, i) != 0)
    return (1);
  return (0);
}

int	check_params_syntax(t_def *def)
{
  if (my_strlen(def->base) < 2)
    return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_BASELEN));
  if (check_char_rep(def->base, 0) != 0)
    return (1);
  if ((check_char_rep(def->structure, 1)) != 0)
    return (1);
  if ((check_twobase(def)) != 0)
    return (1);
  return (0);
}
