/*
** number.h for number in /home/poirie_n/repo/B1/C_Prog_Elem/Bistromathique/strcalc
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Sun Oct 26 02:52:27 2014 Nathan Poirier
** Last update Thu Nov  6 09:47:08 2014 timothy greil
*/

#ifndef NUMBER_H_
# define NUMBER_H_

typedef struct		s_number
{
  char			*nbr;
  int			i;
  struct s_number       *next;
  struct s_number       *prev;
}			t_number;

#endif /* !NUMBER_H_ */
