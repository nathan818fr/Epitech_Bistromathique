/*
** my_strupcase.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 11:04:00 2014 Nathan Poirier
** Last update Wed Oct  8 09:33:50 2014 Nathan Poirier
*/

char	*my_strupcase(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
        {
          str[i] = str[i] + 'A' - 'a';
        }
      i = i + 1;
    }
  return (str);
}
