/*
** stack.h for stack in /home/poirie_n/repo/B1/C_Prog_Elem/Bistromathique/strcalc
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Sun Oct 26 02:52:27 2014 Nathan Poirier
** Last update Fri Nov  7 14:17:13 2014 timothy greil
*/

#ifndef STACK_H_
# define STACK_H_

typedef struct		s_stack
{
  int			i;
  int			first;
  int			last;
  int			side;
  struct s_stack       	*next;
  struct s_stack       	*prev;
}			t_stack;

#endif /* !STACK_H_ */
