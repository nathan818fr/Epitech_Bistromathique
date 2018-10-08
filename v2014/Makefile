##
## Makefile for bistro in /home/poirie_n/repo/B1/C_Prog_Elem/Bistromathique
## 
## Made by Nathan Poirier
## Login   <poirie_n@epitech.net>
## 
## Started on  Mon Nov  3 15:11:40 2014 Nathan Poirier
## Last update Mon Dec  8 14:45:51 2014 Nathan Poirier
##

SRCS	= main.c			\
	  bistro/put_str_in_btree.c	\
	  bistro/put_str_in_btree2.c	\
          bistro/expr_syntax_check1.c   \
          bistro/expr_syntax_check2.c	\
	  bistro/expr_syntax_check3.c   \
	  bistro/free_all.c		\
	  strcalc/strcalc_add.c		\
	  strcalc/strcalc.c		\
	  strcalc/strcalc_utils.c	\
	  strcalc/strcalc_utils2.c	\
	  strcalc/strcalc_sub.c		\
	  strcalc/strcalc_mul.c		\
	  strcalc/strcalc_div.c		\
	  strcalc/strcalc_mod.c		\
	  strcalc/strcalc_base.c	\
	  utils/my_errors.c		\
	  utils/my_get_big_nbr.c

OBJS	= $(addprefix src/, $(SRCS:.c=.o))

LIBS	= -Llib/my -lmy

PROJECT = Bistromathique

NAME	= calc

RM	= rm -f

CC	= gcc -Ofast

MAKELIB	= make -C lib/my/

LIB	= lib/my/libmy.a

CFLAGS	= -W -Wall -Wextra -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -Iinclude/		\
	   -Ilib/my/include/
CFLAGS	+= $(LIBS)

LDFLAGS	=  $(LIBS)

$(PROJECT):	$(LIB) $(NAME)

$(NAME): 	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

$(LIB):
	$(MAKELIB)

all:	$(PROJECT)

clean:
	$(RM) $(OBJS)
	$(MAKELIB) clean

fclean:		clean
	$(MAKELIB) fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	re fclean clean all $(PROJECT)
