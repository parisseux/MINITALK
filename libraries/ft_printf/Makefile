# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 14:57:15 by pchatagn          #+#    #+#              #
#    Updated: 2024/10/15 17:05:53 by pchatagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra 
AR = ar rcs
RM = rm -f

FILES = ft_printf.c \
		ft_conversion.c \
		ft_memory_adress.c \
		ft_print_pourcent.c \
		ft_putchar.c \
		ft_putnbr_hexa.c \
		ft_putnbr_positiv.c \
		ft_putnbr.c \
		ft_putstring.c \

OBJ = $(FILES:.c=.o)

.c.o : 
	${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) 
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean 
	$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclen re