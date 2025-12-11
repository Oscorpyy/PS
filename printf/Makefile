# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/26 09:47:58 by mthetcha          #+#    #+#              #
#    Updated: 2025/11/17 17:16:47 by opernod          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes 
DIR = sources
SRCS = $(DIR)/ft_printf.c $(DIR)/ft_putall.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

$(DIR)/%.o : $(DIR)/%.c includes/ft_printf.h Makefile
	cc $(FLAGS) $(INCLUDES) -c  $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re

