/*
** my_revstr.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 10:45:57 2014 Nathan Poirier
** Last update Tue Oct  7 10:53:17 2014 Nathan Poirier
*/

char    *my_revstr(char *str)
{
  int   i;
  int   l;
  char  c;

  l = 0;
  while (str[l] != '\0')
    {
      l = l + 1;
    }
  i = 0;
  while (i < l / 2)
    {
      c = str[i];
      str[i] = str[l - i - 1];
      str[l - i - 1] = c;
      i = i + 1;
    }
  return (str);
}
