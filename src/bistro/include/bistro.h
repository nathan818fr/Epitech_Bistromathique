/*
** head_bistro.h for header for prototype in /home/greil_t/rendu/Bistromathique/include
** 
** Made by timothy greil
** Login   <greil_t@epitech.net>
** 
** Started on  Sun Oct 26 04:19:06 2014 timothy greil
** Last update Sun Nov  9 17:32:45 2014 timothy greil
*/

#ifndef BISTRO_H_
# define BISTRO_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "bistro_def.h"
#include "strcalc.h"
#include "my_errors.h"
#include "stack.h"
#include "number.h"

#define STDIN_BUFSIZE 8192
#define OP_OPEN_PARENT_IDX 0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX 2
#define OP_SUB_IDX 3
#define OP_MULT_IDX 4
#define OP_DIV_IDX 5
#define OP_MOD_IDX 6

void		*free_all(t_number *, t_stack*);
char		*stack_me_that(t_def *, t_stack **, t_number **, int);
int		skip_parent(t_def *, int);
void		find_first_last(int *, int *, t_def *, t_stack *);
char		*cpy_in_btree_number(t_def *def, int, int);
t_number       	*calc_in_bt(t_stack **, t_number **, t_def *);
t_stack		*new_stack(t_stack *, int , int, int);
t_number	*new_number(t_number *, char *);
char		*str_to_btree_it(t_def *, int, int);
int		is_valid_structure_or_base(t_def *def, int i);
int		countbracket(int bracket, t_def *def, int i);
int		check_bracket(t_def *def, int i);
int		check_operator(t_def *def, int i);
int		check_number(t_def *def, int i);
int		check_twobase(t_def *def);
int		check_char_rep(char *str, char type);
int		next_check(t_def *def, int i);
int		check_params_syntax(t_def *def);
int		check_expr_syntax(t_def *def);
char		*strcalc(char *n1, char *n2, char op, t_def *def);
char		*epur_str(char *str, int, char *);

#endif /* !BISTRO_H_ */
