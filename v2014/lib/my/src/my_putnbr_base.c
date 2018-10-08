/*
** my_putnbr_base.c for day 06 in /home/poirie_n/repo/Piscine/Piscine_C_J06
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Mon Oct  6 14:17:39 2014 Nathan Poirier
** Last update Mon Oct  6 14:50:30 2014 Nathan Poirier
*/

int	my_putnbr_base(int nbr, char *base)
{
  int	l;

  l = 0;
  while (base[l] != '\0')
    {
      l = l + 1;
    }
  if (nbr < 0)
    {
      my_putchar('-');
    }
  else
    {
      nbr = -nbr;
    }
  my_putnbr_base_l(nbr, base, l);
  return (nbr);
}

int	my_putnbr_base_l(int nbr, char *base, int l)
{
  if (nbr <= -l)
    {
      my_putnbr_base_l(nbr / l, base, l);
    }
  my_putchar(base[-(nbr % l)]);
}
