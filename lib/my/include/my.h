/*
** my.h for libmy in /home/poirie_n/repo/lib/libmy
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Fri Oct 10 12:07:11 2014 Nathan Poirier
** Last update Wed Oct 22 09:46:28 2014 Nathan Poirier
*/

#ifndef MY_H_
# define MY_H_

char	*my_strstr(char *str, char *to_find);
char	*my_strncpy(char *dest, char *src, int n);
int	my_isneg(int nb);
int	my_strlen(char *str);
char	*my_strncat(char *dest, char *src, int nb);
char	*my_strupcase(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_square_root(int nb);
char	*my_strcapitalize(char *str);
int	my_find_prime_sup(int nb);
int	my_str_isalpha(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_strncmp(char *s1, char *s2, int n);
int	my_power_rec(int nb, int power);
int	my_strlcat(char *dest, char *src, int size);
char	*my_revstr(char *str);
char	**my_str_to_wordtab(char *str);
int	my_getnbr(char *str);
int	my_str_isprintable(char *str);
char	*my_strcat(char *dest, char *src);
void	my_putchar(char c);
int	my_swap(int *a, int *b);
int	my_putnbr_base(int nbr, char *base);
int	my_is_prime(int nombre);
int	my_put_nbr(int nb);
int	my_str_isnum(char *str);
int	my_str_isupper(char *str);
int	my_str_islower(char *str);
char	*my_strcpy(char *dest, char *src);
int	my_showstr(char *str);
char	*my_strlowcase(char *str);
int	my_putstr(char *str);
int	my_puterror(char *str);
int	my_showmem(char *str, int size);
int	my_show_wordtab(char **tab);

#endif /* !MY_H_ */
