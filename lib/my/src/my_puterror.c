/*
** my_puterror.c for my_puterror in /home/poirie_n/repo/lib/libmy
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Wed Oct 22 09:44:38 2014 Nathan Poirier
** Last update Wed Oct 22 09:45:32 2014 Nathan Poirier
*/

#include <stdlib.h>

int	my_puterror(char *str)
{
  int	i;

  if (str == NULL)
    return (1);
  i = 0;
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
      i = i + 1;
    }
  return (0);
}
