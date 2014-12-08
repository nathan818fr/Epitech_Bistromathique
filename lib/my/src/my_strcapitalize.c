/*
** my_strcapitalize.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 11:06:21 2014 Nathan Poirier
** Last update Wed Oct  8 09:33:10 2014 Nathan Poirier
*/

void	my_strcapitalize_check(char *str, int i, int *u)
{
  char  c;

  c = str[i];
  if (c >= 'a' && c <= 'z')
    {
      if (*u == 1)
        {
          str[i] = str[i] + 'A' - 'a';
          *u = 0;
        }
    }
  else if (c >= '0' && c <= '9')
    {
      *u = 0;
    }
  else if (c < 'A' || c > 'Z')
    {
      *u = 1;
    }
}

char	*my_strcapitalize(char *str)
{
  int   i;
  int   u;

  i = 0;
  u = 1;
  while (str[i] != '\0')
    {
      my_strcapitalize_check(str, i, &u);
      i = i + 1;
    }
  return (str);
}
