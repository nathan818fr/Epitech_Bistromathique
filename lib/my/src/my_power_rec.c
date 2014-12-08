/*
** my_power_rec.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 10:21:23 2014 Nathan Poirier
** Last update Wed Oct  8 09:33:52 2014 Nathan Poirier
*/

int	my_power_rec(int nb, int power)
{
  if (power < 0)
    {
      return (0);
    }
  if (power == 0)
    {
      return (1);
    }
  if (power > 1)
    {
      nb = nb * my_power_rec(nb, power - 1);
    }
  return (nb);
}
