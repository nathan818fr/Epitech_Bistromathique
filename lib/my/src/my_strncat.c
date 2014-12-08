/*
** my_strncat.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 13:39:51 2014 Nathan Poirier
** Last update Tue Oct  7 16:46:38 2014 Nathan Poirier
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	l;

  i = 0;
  while (dest[i])
    {
      i = i + 1;
    }
  l = 0;
  while (src[l] && l < nb)
    {
      dest[i + l] = src[l];
      l = l + 1;
    }
  dest[i + l] = '\0';
  return (dest);
}
