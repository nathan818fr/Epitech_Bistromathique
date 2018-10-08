/*
** my_putstr.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 10:08:29 2014 Nathan Poirier
** Last update Wed Oct 22 09:46:58 2014 Nathan Poirier
*/

#include <stdlib.h>

int	my_putstr(char *str)
{
  int	i;

  if (str == NULL)
    return (1);
  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
