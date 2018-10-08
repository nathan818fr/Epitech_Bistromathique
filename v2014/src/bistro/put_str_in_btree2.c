/*
** put_str_in_btree.c for put a str on btree in /home/greil_t/rendu/Bistromathique
**  
** Made by timothy greil
** Login   <greil_t@epitech.net>
** 
** Started on  Sun Oct 26 05:10:57 2014 timothy greil
** Last update Sun Nov  9 14:00:49 2014 timothy greil
*/

#include "bistro.h"

t_stack		*new_stack(t_stack *node, int i, int f, int side)
{
  t_stack	*new;

  if ((new = malloc(sizeof(t_stack))) == NULL)
    return (NULL);
  if (side == 1)
    {
      new->first = i + 1;
      new->last = f;
    }
  else
    {
      new->first = f;
      new->last = i - 1;
    }
  new->next = NULL;
  new->side = side;
  new->i = i;
  if (node != NULL)
    node->next = new;
  new->prev = node;
  return (new);
}

t_number	*new_number(t_number *node, char *nbr)
{
  t_number	*new;

  if ((new = malloc(sizeof(t_number))) == NULL)
    return (NULL);
  new->nbr = nbr;
  if (node != NULL)
    node->next = new;
  new->prev = node;
  return (new);
}

char		*stack_me_that(t_def *def, t_stack **n, t_number **nb, int i)
{
  t_stack	*node;
  char		*number;
  t_number	*nbr;

  node = *n;
  nbr = *nb;
  if ((node = new_stack(node, i, node->last, 1)) == NULL)
    return (NULL);
  if (i == node->prev->first)
    {
      if ((number = malloc(2)) == NULL)
	return (NULL);
      number[0] = def->base[0];
      number[1] = '\0';
      nbr = new_number(nbr, number);
    }
  else
    {
      if ((node = new_stack(node, i, node->prev->first, 0)) == NULL)
	return (NULL);
    }
  *n = node;
  *nb = nbr;
  return ("OK");
}

t_number	*let_it_go(t_number *nbr)
{
  nbr = nbr->prev->prev;
  free(nbr->next->next->nbr);
  free(nbr->next->next);
  free(nbr->next->nbr);
  free(nbr->next);
  return (nbr);
}

t_number	*calc_in_bt(t_stack **stk, t_number **nb, t_def *def)
{
  t_stack	*node;
  t_stack	*pnode;
  char		*number;
  t_number	*nbr;

  node = *stk;
  if ((number = cpy_in_btree_number(def, node->first, node->last)) == NULL)
    return (NULL);
  if ((nbr = new_number((nbr = *nb), number)) == NULL)
    return (NULL);
  while (node->side == 1)
    {
      number = strcalc(nbr->prev->nbr, nbr->nbr, def->str[node->i], def);
      if (number == NULL)
	return (free_all(nbr, node));
      if ((nbr = new_number((nbr = let_it_go(nbr)), number)) == NULL)
	return (NULL);
      if ((pnode = node->prev)->next != NULL)
	free(node);
      node = pnode;
    }
  *stk = node->prev;
  if (node != NULL)
    free(node);
  return (nbr);
}
