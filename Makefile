# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 16:02:42 by mpascaud          #+#    #+#              #
#    Updated: 2018/02/28 22:30:19 by mpascaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

TAGS = -Wall -Werror -Wextra

SRC = ft_strlen.c ft_atoi.c ft_putchar.c ft_putnbr.c ft_printf.c ft_printf2.c initialisation.c \
	  ft_argument.c ft_cast.c ft_decimal.c ft_decimal2.c nombrechiffres.c ft_character.c ft_string.c \
	  ft_unicharacter.c ft_unistring.c ft_unsigned.c ft_unsigned_hexa.c \


BIN = $(SRC:.c=.o)


all : $(NAME)

$(NAME) :
	gcc $(TAGS) -c $(SRC)
	ar rc $(NAME) $(BIN)
	ranlib $(NAME)

clean:
	rm -fR $(BIN)

fclean: clean
	rm -fR $(NAME)

re: fclean all










