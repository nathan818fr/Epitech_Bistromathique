/*
** my_strlowcase.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 11:04:49 2014 Nathan Poirier
** Last update Tue Oct  7 11:05:12 2014 Nathan Poirier
*/

char    *my_strlowcase(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
        {
          str[i] = str[i] - 'A' + 'a';
        }
      i = i + 1;
    }
  return (str);
}
