/*
** my_strncpy.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 10:42:45 2014 Nathan Poirier
** Last update Wed Oct  8 09:33:50 2014 Nathan Poirier
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int   i;

  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  while (i < n)
    {
      dest[i] = '\0';
      i = i + 1;
    }
  return (dest);
}
