##
## Makefile for libmy in /home/poirie_n/repo/lib/libmy
## 
## Made by Nathan Poirier
## Login   <poirie_n@epitech.net>
## 
## Started on  Tue Oct 28 15:58:10 2014 Nathan Poirier
## Last update Mon Dec  8 14:28:08 2014 Nathan Poirier
##

CC	= cc

RM	= rm -f
CP	= cp

LDFLAGS	=

NAME	= libmy.a

SRC	= my_strstr.c		\
          my_strncpy.c		\
          my_isneg.c		\
          my_strlen.c		\
          my_strncat.c		\
          my_strupcase.c	\
          my_strcmp.c		\
          my_square_root.c	\
          my_strcapitalize.c	\
          my_find_prime_sup.c	\
          my_str_isalpha.c	\
          my_sort_int_tab.c	\
          my_strncmp.c		\
          my_power_rec.c	\
          my_strlcat.c		\
          my_revstr.c		\
          my_str_to_wordtab.c	\
          my_getnbr.c		\
          my_str_isprintable.c	\
          my_strcat.c		\
          my_putchar.c		\
          my_swap.c		\
          my_putnbr_base.c	\
          my_is_prime.c		\
          my_put_nbr.c		\
          my_str_isnum.c	\
          my_str_isupper.c	\
          my_str_islower.c	\
          my_strcpy.c		\
          my_showstr.c		\
          my_strlowcase.c	\
          my_putstr.c		\
          my_showmem.c		\
          my_show_wordtab.c	\
	  my_puterror.c

OBJ	= $(addprefix src/, $(SRC:.c=.o))

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
