/*
** expr_str_check.c for bistro in /home/poirie_n/repo/B1/C_Prog_Elem/Bistromathique/btree
**  
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Sun Oct 26 17:59:12 2014 Nathan Poirier
** Last update Sat Nov  8 16:22:34 2014 timothy greil
*/

#include "bistro.h"

int	is_valid_structure_or_base(t_def *def, int i)
{
  char	a;

  a = def->str[i];
  i = 0;
  while (def->base[i] != '\0')
    {
      if (def->base[i] == a)
	return (0);
      i = i + 1;
    }
  i = 0;
  while (def->structure[i] != '\0')
    {
      if (def->structure[i] == a)
	return (0);
      i = i + 1;
    }
  if (a == '\n')
    return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_READSIZE_LONG));
  return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_INVALID_CHAR));
}

int	countbracket(int bracket, t_def *def, int i)
{
  if (def->str[i] == def->structure[OP_OPEN_PARENT_IDX])
    bracket = bracket + 1;
  if (def->str[i] == def->structure[OP_CLOSE_PARENT_IDX])
    bracket = bracket - 1;
  return (bracket);
}

int	check_bracket(t_def *def, int i)
{
  if (def->str[i] == def->structure[OP_OPEN_PARENT_IDX])
    {
      if (def->str[i + 1] == def->structure[OP_CLOSE_PARENT_IDX])
	return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_BRACKET1));
      if (def->str[i + 1] == def->structure[OP_MULT_IDX] ||
	  def->str[i + 1] == def->structure[OP_DIV_IDX] ||
	  def->str[i + 1] == def->structure[OP_MOD_IDX])
	return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_BRACKET2));
    }
  if (def->str[i] == def->structure[OP_CLOSE_PARENT_IDX])
    {
      if (def->str[i + 1] != def->structure[OP_PLUS_IDX] &&
	  def->str[i + 1] != def->structure[OP_SUB_IDX] &&
	  def->str[i + 1] != def->structure[OP_MULT_IDX] &&
	  def->str[i + 1] != def->structure[OP_DIV_IDX] &&
	  def->str[i + 1] != def->structure[OP_MOD_IDX] &&
	  def->str[i + 1] != def->structure[OP_CLOSE_PARENT_IDX] &&
	  def->str[i + 1] != '\0')
	return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_BRACKET3));
      if (def->str[i + 1] == def->structure[OP_OPEN_PARENT_IDX])
	return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_BRACKET4));
    }
  return (0);
}

int	extend_check_op(t_def *def, int i)
{
  if (def->str[i] == def->structure[OP_PLUS_IDX] ||
      def->str[i] == def->structure[OP_SUB_IDX])
    {
      if (def->str[i + 1] == def->structure[OP_MULT_IDX] ||
	  def->str[i + 1] == def->structure[OP_DIV_IDX] ||
	  def->str[i + 1] == def->structure[OP_MOD_IDX])
	return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_OP1));
      if (def->str[i + 1] == def->structure[OP_CLOSE_PARENT_IDX])
	return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_OP2));
      if (def->str[i + 1] == '\0')
	return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_OP3));
    }
  return (0);
}

int	check_operator(t_def *def, int i)
{
  if (extend_check_op(def, i) != 0)
    return (1);
  if (def->str[i] == def->structure[OP_MULT_IDX] ||
      def->str[i] == def->structure[OP_DIV_IDX] ||
      def->str[i] == def->structure[OP_MOD_IDX])
    {
      if (def->str[i + 1] == def->structure[OP_CLOSE_PARENT_IDX])
	return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_OP1));
      if (def->str[i + 1] == def->structure[OP_MULT_IDX] ||
	  def->str[i + 1] == def->structure[OP_DIV_IDX] ||
	  def->str[i + 1] == def->structure[OP_MOD_IDX])
	return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_OP4));
      if (def->str[i + 1] == '\0' || i == 0)
	return (my_error2(SYNTAXE_ERROR_MSG, SYNTAXE_ERROR_OP5));
    }
  return (0);
}
