# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/31 12:28:26 by abdel-ke          #+#    #+#              #
#    Updated: 2020/01/14 14:10:37 by abdel-ke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =	ft_stock.c		\
		ft_check.c 			\
		ft_count_number.c 	\
		ft_minus.c 			\
		ft_printf.c 		\
		ft_point.c			\
		ft_putchar.c 		\
		ft_putnbr.c			\
		init_struct.c		\
		ft_type.c			\
		ft_write_d/ft_print_d.c		\
		ft_write_d/ft_function_d.c\
		ft_write_d/ft_finish_d.c\
		ft_return_type.c	\
		ft_write_s/ft_print_s.c\
		ft_write_s/ft_finish_s.c\
		ft_strlen.c			\
		ft_putstr.c			\
		ft_write_c/ft_print_c.c \
		ft_write_x/ft_print_x.c \
		ft_write_x/ft_hexadecimal.c \
		ft_write_x/ft_function_x.c \
		ft_write_u/ft_print_u.c		\
		ft_write_u/ft_function_u.c\
		ft_write_p/ft_print_p.c		\
		ft_write_pcentage/ft_write_pcentage.c

OBJ		= $(SRC:.c=.o)

all		: $(NAME)
$(NAME)	: $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)
clean 	:
	rm -f *.o
	rm -f ft_write_d/*.o
	rm -f ft_write_S/*.o
	rm -f ft_write_c/*.o
	rm -f ft_write_x/*.o
	rm -f ft_write_u/*.o
	rm -f ft_write_p/*.o
	rm -f ft_write_pcentage/*.o
fclean 	: clean
	rm -f $(NAME)
re 		: fclean all
