/*
** my_strncmp.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 10:57:20 2014 Nathan Poirier
** Last update Tue Oct  7 10:57:41 2014 Nathan Poirier
*/

int     my_strncmp(char *s1, char *s2, int n)
{
  int   i;

  if (n <= 0)
    {
      return (0);
    }
  i = 0;
  while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    {
      i = i + 1;
    }
  return (s1[i] - s2[i]);
}
