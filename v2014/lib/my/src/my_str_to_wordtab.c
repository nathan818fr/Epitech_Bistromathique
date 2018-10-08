/*
** my_str_to_wordtab.c for day 08 in /home/poirie_n/repo/Piscine/Piscine_C_J08
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Wed Oct  8 14:47:08 2014 Nathan Poirier
** Last update Sat Nov  1 20:32:29 2014 timothy greil
*/

#include <stdio.h>
#include <stdlib.h>

int	my_str_tw_is_separator(char c)
{
  if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c < '0' || c > '9'))
    {
      return (1);
    }
  return (0);
}

int	my_str_tw_count(char *str)
{
  int   i;
  int   tab_i;
  int   car_pos;
  int   sep_pos;

  i = 0;
  tab_i = 0;
  car_pos = -1;
  sep_pos = -1;
  while (i == 0 || str[i - 1])
    {
      if (my_str_tw_is_separator(str[i]))
        {
          if (car_pos > sep_pos)
            {
              tab_i = tab_i + 1;
            }
          sep_pos = i;
        }
      else
          car_pos = i;
      i = i + 1;
    }
  return (tab_i);
}

void    my_str_tw_put_to(char *str, char *dest, int s, int e)
{
  int   i;

  i = 0;
  while (s <= e)
    {
      dest[i] = str[s];
      i = i + 1;
      s = s + 1;
    }
  dest[i] = '\0';
}

void	my_str_tw_put(char *str, char **dest, int total)
{
  int	i;
  int	tab_i;
  int	car_pos;
  int	sep_pos;

  i = -1;
  tab_i = 0;
  car_pos = -1;
  sep_pos = -1;
  while ((i = i + 1) == 0 || str[i - 1])
    {
      if (my_str_tw_is_separator(str[i]))
	{
	  if (car_pos > sep_pos)
	    {
	      dest[tab_i] = malloc(sizeof(char) * (car_pos - sep_pos));
	      my_str_tw_put_to(str, dest[tab_i], sep_pos + 1, car_pos);
	      tab_i = tab_i + 1;
	    }
	  sep_pos = i;
	}
      else
	  car_pos = i;
    }
}

char	**my_str_to_wordtab(char *str)
{
  int	l;
  char	**dest;

  l = my_str_tw_count(str);
  if ((dest = malloc(sizeof(char *) * (l + 1))) == NULL)
    return (NULL);
  my_str_tw_put(str, dest, l);
  dest[l] = 0;
  return (dest);
}
