/*
** strcalc.h for strclalc in /home/poirie_n/repo/B1/C_Prog_Elem/Bistromathique/strcalc
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Sun Oct 26 02:52:27 2014 Nathan Poirier
** Last update Sun Nov  9 17:46:29 2014 timothy greil
*/

#ifndef STRCALC_H_
# define STRCALC_H_

typedef struct	s_strnb
{
  char		*str;
  int		strlen;
  char		is_neg;
}		t_strnb;

t_strnb	*strcalc_create_strnb(int str_len);
void    strcalc_reset_strnb(t_strnb *strnb, int len);
t_strnb	*strcalc_str_to_strnb(char *str, t_def *def);
char	*strcalc_strnb_to_str(t_strnb *strnb, t_def *def);

int     strcalc_strnb_is_zero(t_strnb *nb);
int     strcalc_strnb_cmp(t_strnb *nb1, t_strnb *nb2, t_def *def);
void	strcalc_swap(t_strnb **nb1, t_strnb **nb2);
int     strcalc_max(int a, int b);
void    strcalc_strnb_cpy(t_strnb *src, t_strnb *dst);

void    strcalc_strnb_baseup(t_strnb *nb);
void    strcalc_strnb_basedown(t_strnb *nb);
void	strcalc_strnb_updatelen(t_strnb *nb);
int     strcalc_strnb_is_zero2(t_strnb *nb);

char    *strcalc(char *n1, char *n2, char op, t_def *def);
t_strnb	*strcalc_add(t_strnb *nb1, t_strnb *nb2, t_def *def);
t_strnb	*strcalc_sub(t_strnb *nb1, t_strnb *nb2, t_def *def);
t_strnb *strcalc_mul(t_strnb *nb1, t_strnb *nb2, t_def *def);
t_strnb *strcalc_div(t_strnb *nb1, t_strnb *nb2, t_def *def);
t_strnb *strcalc_mod(t_strnb *nb1, t_strnb *nb2, t_def *def);

int     from_base(char c, t_def *def);
char	to_base(int i, t_def *def);
char	*to_base_str(int i, t_def *def);
int	strcalc_strnb_free(t_strnb *nb);

#endif /* !STRCALC_H_ */
