/*
** main.c for main test in /home/greil_t/rendu/Bistromathique
**  
** Made by timothy greil
** Login   <greil_t@epitech.net>
** 
** Started on  Sun Oct 26 04:01:35 2014 timothy greil
** Last update Wed Nov 19 11:51:34 2014 Nathan
*/

#include "bistro.h"
#include "my_utils.h"

char		*stdin_str(unsigned int maxsize)
{
  unsigned int	size;
  char		*str;
  char		buffer[STDIN_BUFSIZE];
  unsigned int	i;
  unsigned int	p;

  if ((str = malloc(maxsize + 1)) == NULL)
    return (my_error(RUNTIME_ERROR_MSG, RUNTIME_ERROR_MEMORY));
  p = 0;
  while (p < maxsize && (size = read(0, buffer, STDIN_BUFSIZE)) > 0)
    {
      i = 0;
      while (i < size && p < maxsize)
	{
	  str[p] = buffer[i];
	  i = i + 1;
	  p = p + 1;
	}
    }
  str[p] = '\0';
  return (str);
}

int	initialize(char **av, t_def *def)
{
  if ((def->size = my_get_big_nbr(av[3])) <= 0)
    return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_READSIZE));
  def->base = av[1];
  def->structure = av[2];
  def->lenofbase = my_strlen(def->base);
  if (check_params_syntax(def) != 0)
    return (1);
  if ((def->str = stdin_str(def->size)) == NULL)
    return (1);
  if (check_expr_syntax(def) != 0)
    return (1);
  return (0);
}

int	print_usage()
{
  my_puterror("Usage: stdin > ./calc base operators size_read\n\n");
  my_puterror("Example:\n");
  my_puterror("echo \"17*(-2)\" | ./calc \"0123456789\" \"()+-*/%\" 7\n");
  return (1);
}

int	main(int ac, char **av)
{
  char	*str;
  t_def *def;

  if (ac != 4)
    return (print_usage());
  if ((def = malloc(sizeof(t_def))) == NULL)
    return (my_error2(RUNTIME_ERROR_MSG, RUNTIME_ERROR_MEMORY));
  if ((def->var = malloc(sizeof(t_var))) == NULL)
    return (my_error2(RUNTIME_ERROR_MSG, RUNTIME_ERROR_MEMORY));
  if (initialize(av, def) != 0)
    return (1);
  str = str_to_btree_it(def, 0, def->size - 1);
  free(def->str);
  free(def->var);
  free(def);
  if (str == NULL)
    return (1);
  my_putstr(str);
  free(str);
  return (0);
}
