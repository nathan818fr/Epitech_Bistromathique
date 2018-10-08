/*
** expr_syntax_check3.c for bistro in /home/poirie_n/repo/B1/C_Prog_Elem/Bistromathique
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Fri Nov  7 13:46:04 2014 Nathan Poirier
** Last update Sat Nov  8 17:17:34 2014 Nathan Poirier
*/

#include "bistro.h"

int		check_expr_syntax(t_def *def)
{
  int		bracket;
  unsigned int	i;

  bracket = 0;
  i = 0;
  while (i < def->size)
    {
      if ((next_check(def, i)) != 0)
        return (1);
      if ((bracket = countbracket(bracket, def, i)) < 0)
	return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_BRACKET6));
      i = i + 1;
    }
  if (bracket != 0)
    return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_BRACKET7));
  return (0);
}
