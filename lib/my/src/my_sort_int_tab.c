/*
** my_sort_int_tab.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 10:17:13 2014 Nathan Poirier
** Last update Wed Oct  8 09:32:05 2014 Nathan Poirier
*/

void	my_sort_int_tab(int *tab, int size)
{
  int   e;

  e = -1;
  while (e != 0)
    {
      e = my_sort_int_tab_exec(tab, size);
    }
}

int	my_sort_int_tab_exec(int *tab, int size)
{
  int   e;
  int   i;
  int   a;
  int   b;

  e = 0;
  i = 0;
  while (i < size - 1)
    {
      a = tab[i];
      b = tab[i + 1];
      if (a > b)
        {
          tab[i] = b;
          tab[i + 1] = a;
          e = e + 1;
        }
      i = i + 1;
    }
  return (e);
}
