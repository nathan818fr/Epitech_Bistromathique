/*
** my_showmem.c for libmy in /home/poirie_n/repo/Piscine/Piscine_C_J07/lib/my
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Tue Oct  7 16:20:55 2014 Nathan Poirier
** Last update Wed Oct  8 14:12:47 2014 Nathan Poirier
*/

void	my_showmem_line_addr(long nbr, char *base, int l, int nb)
{
  if (nb > 1)
    {
      my_showmem_line_addr(nbr / l, base, l, nb - 1);
    }
  my_putchar(base[nbr % l]);
  if (nb == 8)
    {
      my_putchar(':');
      my_putchar(' ');
    }
}

void	my_showmem_line_hex(char *str, int size)
{
  char	*hexbase;
  int	i;

  hexbase = "0123456789abcdef";
  i = 0;
  while (i < size)
    {
      my_putchar(hexbase[(*(str + i) / 16) % 16]);
      my_putchar(hexbase[*(str + i) % 16]);
      if (i % 2 == 1)
	  my_putchar(' ');
      i = i + 1;
    }
  while (i < 16)
    {
      my_putchar(' ');
      my_putchar(' ');
      if (i % 2 == 1)
	my_putchar(' ');
      i = i + 1;
    }
}

void    my_showmem_line(char *str, int size)
{
  int   i;

  my_showmem_line_addr((long)str, "0123456789abcdef", 16, 8);
  my_showmem_line_hex(str, size);
  my_putchar(' ');
  i = 0;
  while (i < size)
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  my_putchar('\n');
}

int	my_showmem(char *str, int size)
{
  int	i;
  int	l;

  i = 0;
  while (i < size) {
    l = size - i;
    if (l > 16)
      {
	l = 16;
      }
    my_showmem_line(str + i, l);
    i = i + 16;
  }
  return (0);
}
