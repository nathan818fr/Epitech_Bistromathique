/*
** my_getnbr.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 10:13:54 2014 Nathan Poirier
** Last update Tue Oct  7 10:15:03 2014 Nathan Poirier
*/

int     my_getnbr(char *str)
{
  int   sign;
  int   nb_start;
  int   nb_end;
  int   n;
  int   l;

  if (str[0] == '\0')
    {
      return (0);
    }
  sign = 1;
  nb_start = -1;
  nb_end = -1;
  l = my_getnbr_parse(str, &nb_start, &nb_end, &sign);
  if (nb_start != -1 && nb_end == -1)
    {
      nb_end = l;
    }
  if (nb_end - nb_start > 10)
    {
      return (0);
    }
  n = my_getnbr_add(str, nb_start, nb_end, sign);
  return (n);
}

int     my_getnbr_parse(char *str, int *nb_start, int *nb_end, int *sign)
{
  char  c;
  int   l;

  l = 0;
  while (str[l] != '\0' && *nb_end == -1)
    {
      c = str[l];
      if (c == '-' && *nb_start == -1)
        {
          *sign = *sign * -1;
        }
      else if (c >= '0' && c <= '9')
        {
          if (*nb_start == -1 && c != '0')
            {
              *nb_start = l;
            }
        }
      else if (c != '+' || *nb_start != -1)
        {
          *nb_end = l;
        }
      l = l + 1;
    }
  return (l);
}

int     my_getnbr_add(char *str, int nb_start, int nb_end, int sign)
{
  int   n;
  int   pn;
  int   i;
  int   dec;

  n = 0;
  pn = 0;
  dec = 1;
  i = nb_end - 1;
  while (i >= nb_start)
    {
      n = n + (sign * (str[i] - '0') * dec);
      if (sign == 1 && n < pn)
        {
          return (0);
        }
      else if (sign == -1 && n > pn)
        {
          return (0);
        }
      pn = n;
      dec = dec * 10;
      i = i - 1;
    }
  return (n);
}
