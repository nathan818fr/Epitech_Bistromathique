SRCS	=	main.c \
            eval/eval.c \
            eval/eval_brace.c \
            eval/eval_branch.c \
            eval/eval_branch_insert.c \
            eval/eval_branch_set.c \
            eval/eval_branch_calc.c \
            eval/eval_nb.c \
            eval/eval_op.c \
            eval/eval_stack.c \
            eval/eval_utils.c \
            number/number.c \
            number/number_utils.c \
            utils/bistro_utils.c \
            utils/bistro_get_nbr.c \
            utils/my_putstr.c \
            utils/my_strlen.c \
            utils/my_memset.c \
            utils/my_putnbr.c \
            calc/calc.c \
            calc/calc_add.c \
            calc/calc_sub.c \
            calc/calc_utils.c \
            calc/calc_mult.c \
            calc/calc_div.c \
            calc/calc_mod.c

OBJS	=	$(addprefix src/, $(SRCS:.c=.o))

PROJECT =	Bistro-Matic

NAME	=	$(if $(CLION_EXE_DIR),$(CLION_EXE_DIR)/,)calc

CC	= 	cc

RM	=	rm -f

CFLAGS	=	-std=c99 -pedantic
CFLAGS 	+=	-Wextra -Wall -Werror -Wno-unused-parameter
CFLAGS	+=	-I./include/
CFLAGS 	+=	--coverage
ifeq ($(BISTRO_DEBUG), 1)
CFLAGS += -g -DBISTRO_DEBUG
else
CFLAGS += -Ofast
endif

all:		$(PROJECT)

$(PROJECT):	$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: re fclean clean all $(PROJECT)
