/*
** my_errors.h for errors in /home/poirie_n/repo/B1/C_Prog_Elem/Bistromathique/strcalc
** 
** Made by Nathan Poirier
** Login   <poirie_n@epitech.net>
** 
** Started on  Mon Oct 27 23:48:51 2014 Nathan Poirier
** Last update Sun Nov  9 13:39:34 2014 timothy greil
*/

#ifndef MY_ERRORS_H_
# define MY_ERRORS_H_

# define SYNTAXE_ERROR_MSG		"Syntax error: "
# define SYNTAXE_ERROR_READSIZE		"size_read must be a strictly positive\
 integer"
# define SYNTAXE_ERROR_READSIZE_LONG	"Invalid size_read (too long) or new\
 line in expression"
# define SYNTAXE_ERROR_BASELEN		"The base must contain at least 2\
 characters"
# define SYNTAXE_ERROR_OPLEN		"The operators must contain 7\
 characters"
# define SYNTAXE_ERROR_BASE_REP		"Same character is present twice in\
 the base"
# define SYNTAXE_ERROR_OP_REP		"Same character is present twice in\
 the operators"
# define SYNTAXE_ERROR_BASEOP_REP	"Same character is present in base\
 and operators"
# define SYNTAXE_ERROR_INVALID_CHAR	"Unknown character in expression"
# define SYNTAXE_ERROR_BRACKET1		"Close bracket after an open bracket"
# define SYNTAXE_ERROR_BRACKET2		"Operator after an open bracket"
# define SYNTAXE_ERROR_BRACKET3		"No operator after a close bracket"
# define SYNTAXE_ERROR_BRACKET4		"Open bracket after a close bracket"
# define SYNTAXE_ERROR_BRACKET5		"Open bracket after a number"
# define SYNTAXE_ERROR_BRACKET6		"Invalid close bracket"
# define SYNTAXE_ERROR_BRACKET7		"Bad number of bracket"
# define SYNTAXE_ERROR_OP1		"Bad operators order"
# define SYNTAXE_ERROR_OP2		"Close bracket after an operator"
# define SYNTAXE_ERROR_OP3		"Operator at end of expression"
# define SYNTAXE_ERROR_OP4		"Bad operator just after another\
 operator"
# define SYNTAXE_ERROR_OP5		"Bad operator at start or end"

# define RUNTIME_ERROR_MSG		"Runtime error: "
# define RUNTIME_ERROR_MEMORY		"Out of memory"
# define RUNTIME_ERROR_DIVZERO		"Division by zero"
# define RUNTIME_ERROR_MODZERO		"Modulo by zero"

void	*my_error(char *type, char *msg);
int	my_error2(char *type, char *msg);

#endif /* !MY_ERRORS_H_ */
