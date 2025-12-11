# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 16:14:19 by lgoderne          #+#    #+#              #
#    Updated: 2025/11/21 16:07:10 by lgoderne         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = cc 
C_FLAGS = -Werror -Wall -Wextra
NAME = libft.a
SRCS = ft_isalpha.c\
ft_isdigit.c\
ft_isalnum.c\
ft_isascii.c\
ft_isprint.c\
ft_strlen.c\
ft_memset.c\
ft_bzero.c\
ft_memcpy.c\
ft_memmove.c\
ft_strlcpy.c\
ft_strlcat.c\
ft_toupper.c\
ft_tolower.c\
ft_strchr.c\
ft_strrchr.c\
ft_strncmp.c\
ft_memchr.c\
ft_memcmp.c\
ft_strnstr.c\
ft_atoi.c\
ft_calloc.c\
ft_strdup.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_itoa.c\
ft_substr.c\
ft_strjoin.c\
ft_strtrim.c\
ft_split.c\
ft_strmapi.c\
ft_striteri.c

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstnew_bonus.c\
ft_lstadd_front_bonus.c\
ft_lstsize_bonus.c\
ft_lstlast_bonus.c\
ft_lstadd_back_bonus.c\
ft_lstclear_bonus.c\
ft_lstdelone_bonus.c\
ft_lstiter_bonus.c\
ft_lstmap_bonus.c

BONUS_BUILT = .bonus_built
BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): %.o : %.c libft.h Makefile
	$(CC) $(C_FLAGS) -c $< -o $@

bonus: $(BONUS_BUILT)

$(BONUS_BUILT): $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	touch $(BONUS_BUILT)

$(BONUS_OBJS): %.o : %.c libft.h Makefile
	$(CC) $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_BUILT)

re: fclean all

.PHONY: all clean fclean re bonus