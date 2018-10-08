/*
** put_str_in_btree.c for put a str on btree in /home/greil_t/rendu/Bistromathique
**  
** Made by timothy greil
** Login   <greil_t@epitech.net>
** 
** Started on  Sun Oct 26 05:10:57 2014 timothy greil
** Last update Sat Nov  8 15:03:03 2014 timothy greil
*/

#include "bistro.h"

int	skip_parent(t_def *def, int i)
{
  int	nbparent;

  i = i - 1;
  nbparent = 1;
  while (nbparent != 0)
    {
      if (def->str[i] == def->structure[OP_CLOSE_PARENT_IDX])
	nbparent = nbparent + 1;
      if (def->str[i] == def->structure[OP_OPEN_PARENT_IDX])
	nbparent = nbparent - 1;
      i = i - 1;
    }
  return (i);
}

int	find_the_operator(t_def *def, int first, int last)
{
  int	firstop;
  int	i;

  i = last + 1;
  firstop = -1;
  while ((i = i - 1) >= first)
    {
      if (def->str[i] == def->structure[OP_CLOSE_PARENT_IDX])
	i = skip_parent(def, i);
      if (i < first)
	return (firstop);
      if ((def->str[i] == def->structure[OP_SUB_IDX] ||
	   def->str[i] == def->structure[OP_PLUS_IDX]) &&
	  (i - 1 < first || ((def->str[i - 1] != def->structure[OP_PLUS_IDX] &&
			      def->str[i - 1] != def->structure[OP_SUB_IDX] &&
			      def->str[i - 1] != def->structure[OP_MULT_IDX] &&
			      def->str[i - 1] != def->structure[OP_DIV_IDX] &&
			      def->str[i - 1] != def->structure[OP_MOD_IDX]))))
	return (i);
      if (firstop == -1 && (def->str[i] == def->structure[OP_MULT_IDX] ||
			    def->str[i] == def->structure[OP_DIV_IDX] ||
			    def->str[i] == def->structure[OP_MOD_IDX]))
	firstop = i;
    }
  return (firstop);
}

char	*cpy_in_btree_number(t_def *def, int first, int last)
{
  char	*number;
  int	nb;

  nb = 0;
  while (def->str[first] == def->structure[0])
    {
      first = first + 1;
      last = last - 1;
    }
  while (def->str[first] == def->base[0] && first < last)
    first = first + 1;
  if ((number = malloc(last - first + 2)) == NULL)
    return (NULL);
  while (first + nb < last + 1)
    {
      number[nb] = def->str[first + nb];
      nb = nb + 1;
    }
  number[nb] = '\0';
  return (number);
}

void	find_first_last(int *f, int *l, t_def *def, t_stack *node)
{
  int	first;
  int	last;

  first = node->first;
  last = node->last;
  while (def->str[last] == def->structure[OP_CLOSE_PARENT_IDX] &&
	 skip_parent(def, last) == first - 1)
    {
      first = first + 1;
      last = last - 1;
    }
  node->first = first;
  node->last = last;
  *f = first;
  *l = last;
}

char		*str_to_btree_it(t_def *def, int first, int last)
{
  t_stack	*node;
  t_number	*nbr;
  char		*number;
  int		i;

  if ((node = new_stack(NULL, 0, first, 0)) == NULL)
    return (NULL);
  node->last = last;
  if ((nbr = new_number(NULL, NULL)) == NULL)
    return (NULL);
  while (node != NULL)
    {
      find_first_last(&first, &last, def, node);
      if ((i = find_the_operator(def, first, last)) == -1)
	nbr = calc_in_bt(&node, &nbr, def);
      else
	number = stack_me_that(def, &node, &nbr, i);
      if (nbr == NULL || number == NULL)
	return (NULL);
    }
  number = nbr->nbr;
  free(nbr->prev);
  free(nbr);
  return (number);
}
