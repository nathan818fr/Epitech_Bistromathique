/*
** errors.c for calc in /home/poirie_n/repo/B1/C_Prog_Elem/Bistromathique/strcalc
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Mon Oct 27 23:34:12 2014 Nathan Poirier
** Last update Sat Nov  8 17:03:07 2014 Nathan Poirier
*/

#include "bistro.h"

void	*my_error(char *type, char *msg)
{
  my_puterror(type);
  my_puterror(msg);
  my_puterror(".");
  return (NULL);
}

int	my_error2(char *type, char *msg)
{
  my_error(type, msg);
  return (1);
}
