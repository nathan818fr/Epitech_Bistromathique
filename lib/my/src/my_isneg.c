/*
** my_isneg.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 09:51:24 2014 Nathan Poirier
** Last update Tue Oct  7 16:48:01 2014 Nathan Poirier
*/

int	my_isneg(int nb)
{
  if (nb >= 0)
    {
      my_putchar('P');
    }
  else
    {
      my_putchar('N');
    }
  return (0);
}
