/*
** def_bistro.h for define all in /home/greil_t/rendu/Piscine_C_eval_expr/include
** 
** Made by timothy greil
** Login   <greil_t@epitech.net>
** 
** Started on  Tue Oct 21 19:08:19 2014 timothy greil
** Last update Sun Nov  9 18:03:23 2014 timothy greil
*/

#ifndef BISTRO_DEF_H_
# define BISTRO_DEF_H_

typedef struct	s_var
{
  int		i;
  int		j;
  int		k;
  char		can_free;
}		t_var;

typedef struct	s_def
{
  char		*str;
  char		*base;
  int		lenofbase;
  char		*structure;
  unsigned int	size;
  t_var		*var;
}		t_def;

#endif /* !BISTRO_DEF_H_ */
