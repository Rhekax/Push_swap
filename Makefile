NAME = push_swap
SOURCE = push_swap.c swap_utils.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFTPATH = libft/
PRINTFPATH = ft_printf/
PRINTFLIB = ft_printf/libftprintf.a
LIBFTLIB = libft/libft.a
OBJ = ${SOURCE:%.c=%.o}

all: ${NAME} push_swap.h clean


${NAME}: ${OBJ} ${PRINTFLIB} ${LIBFTLIB}
	@${CC} ${CFLAGS} ${OBJ} ${PRINTFLIB} ${LIBFTLIB} -o run

${PRINTFLIB} :
	@make -C ${PRINTFPATH}

${LIBFTLIB} :
	@make -C ${LIBFTPATH}

%.o : %.c
	@$(CC)	$(CFLAGS)	-c	$<	-o	$@

clean :
	@make -C ${PRINTFPATH} clean
	@make -C ${LIBFTPATH} clean
	@rm -rf ${OBJ}

fclean :
	@make -C ${PRINTFPATH} fclean
	@make -C ${LIBFTPATH} fclean
	@rm -rf  ${OBJ} ${NAME}

re : fclean all clean

.PHONY: fclean clean re all