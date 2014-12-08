/*
** free_all.c for free put in /home/greil_t/rendu/Bistromathique
** 
** Made by timothy greil
** Login   <greil_t@epitech.net>
** 
** Started on  Sat Nov  8 14:58:48 2014 timothy greil
** Last update Sat Nov  8 15:02:53 2014 timothy greil
*/

#include "bistro.h"

void		*free_all(t_number *nbr, t_stack *node)
{
  t_number	*pnbr;
  t_stack	*pnode;

  while (nbr != NULL)
    {
      pnbr = nbr->prev;
      if (nbr->nbr != NULL)
	free(nbr->nbr);
      free(nbr);
      nbr = pnbr;
    }
  while (node != NULL)
    {
      pnode = node->prev;
      free(node);
      node = pnode;
    }
  return (NULL);
}
