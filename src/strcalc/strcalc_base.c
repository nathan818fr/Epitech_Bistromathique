/*
** strcalc_base.c for strcalc in /home/poirie_n/repo/B1/C_Prog_Elem/Bistromathique/strcalc
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Thu Oct 30 14:51:12 2014 Nathan Poirier
** Last update Wed Nov  5 15:58:24 2014 Nathan Poirier
*/

#include "bistro.h"

int	from_base(char c, t_def *def)
{
  int	i;

  i = 0;
  while (i < def->lenofbase)
    {
      if (def->base[i] == c)
	return (i);
      i = i + 1;
    }
  return (0);
}

char	to_base(int i, t_def *def)
{
  return (def->base[i]);
}

char    *to_base_str(int i, t_def *def)
{
  char	*dest;

  if ((dest = malloc(2)) == NULL)
    return (NULL);
  dest[0] = def->base[i];
  dest[1] = '\0';
  return (dest);
}
