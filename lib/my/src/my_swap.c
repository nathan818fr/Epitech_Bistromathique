/*
** my_swap.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 10:01:06 2014 Nathan Poirier
** Last update Wed Oct  8 09:28:10 2014 Nathan Poirier
*/

int	my_swap(int *a, int *b)
{
  int   c;

  c = *a;
  *a = *b;
  *b = c;
}
