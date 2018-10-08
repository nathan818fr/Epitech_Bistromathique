/*
** my_strcat.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 11:23:09 2014 Nathan Poirier
** Last update Tue Oct  7 13:37:45 2014 Nathan Poirier
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	l;

  i = 0;
  while (dest[i])
    {
      i = i + 1;
    }
  l = 0;
  while (src[l])
    {
      dest[i + l] = src[l];
      l = l + 1;
    }
  dest[i + l] = '\0';
  return (dest);
}
