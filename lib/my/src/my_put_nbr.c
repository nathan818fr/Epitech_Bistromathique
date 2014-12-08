/*
** my_put_nbr.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 09:54:38 2014 Nathan Poirier
** Last update Tue Oct  7 09:58:50 2014 Nathan Poirier
*/

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
    }
  else
    {
      nb = -nb;
    }
  my_put_nbr_disp(nb);
}

int	my_put_nbr_disp(int nb)
{
  if (nb <= -10)
    {
      my_put_nbr_disp(nb / 10);
    }
  my_putchar('0' - nb % 10);
}
