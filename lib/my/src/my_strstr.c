/*
** my_strstr.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 10:53:43 2014 Nathan Poirier
** Last update Tue Oct  7 11:40:20 2014 Nathan Poirier
*/

#include <stdlib.h>

char    *my_strstr(char *str, char *to_find)
{
  int   i;
  int   f;

  i = 0;
  f = 0;
  if (to_find[0] == '\0')
    return (str);
  while (str[i] != '\0')
    {
      if (str[i] == to_find[f])
        {
          f = f + 1;
          if (to_find[f] == '\0')
              return (str + i - f + 1);
        }
      else if (f != 0)
        {
	  i = i - f;
          f = 0;
        }
      i = i + 1;
    }
  return (NULL);
}
