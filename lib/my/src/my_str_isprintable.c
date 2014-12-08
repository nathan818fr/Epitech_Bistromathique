/*
** my_str_isprintable.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 11:11:34 2014 Nathan Poirier
** Last update Tue Oct  7 11:11:44 2014 Nathan Poirier
*/

int     my_str_isprintable(char *str)
{
  int   i;
  char  c;

  i = 0;
  while (str[i] != '\0')
    {
      c = str[i];
      if (c < 32 || c > 126)
        {
          return (0);
        }
      i = i + 1;
    }
  return (1);
}
