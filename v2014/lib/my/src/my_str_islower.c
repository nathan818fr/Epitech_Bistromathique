/*
** my_str_islower.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 11:10:31 2014 Nathan Poirier
** Last update Fri Oct 10 12:06:16 2014 Nathan Poirier
*/

int	my_str_islower(char *str)
{
  int   i;
  char  c;

  i = 0;
  while (str[i] != '\0')
    {
      c = str[i];
      if (c < 'a' || c > 'z')
        {
          return (0);
        }
      i = i + 1;
    }
  return (1);
}
