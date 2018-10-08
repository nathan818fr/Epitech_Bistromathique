/*
** my_show_wordtab.c for day 08 in /home/poirie_n/repo/Piscine/Piscine_C_J08
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Thu Oct  9 11:22:41 2014 Nathan Poirier
** Last update Thu Oct  9 11:27:04 2014 Nathan Poirier
*/

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
}
