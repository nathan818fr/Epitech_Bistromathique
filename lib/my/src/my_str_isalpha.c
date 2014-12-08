/*
** my_str_isalpha.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 11:09:01 2014 Nathan Poirier
** Last update Wed Oct  8 09:33:13 2014 Nathan Poirier
*/

int	my_str_isalpha(char *str)
{
  int   i;
  char  c;

  i = 0;
  while (str[i] != '\0')
    {
      c = str[i];
      if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
        {
          return (0);
        }
      i = i + 1;
    }
  return (1);
}
