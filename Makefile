# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 15:35:41 by opernod           #+#    #+#              #
#    Updated: 2025/12/22 13:35:19 by opernod          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I includes -I libft

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC_DIR		= sources
OP_DIR		= operations

# Operations files located in sources/operations
OP_FILES	= pa.c pb.c \
			  ra.c rb.c rr.c \
			  rra.c rrb.c rrr.c \
			  sa.c sb.c ss.c

# Main source files located in sources/
SRC_FILES	= adaptive.c \
			  args_to_int.c \
			  bucket_sort.c \
			  disorder.c \
			  ft_atol.c \
			  ft_strcmp.c \
			  get_agrs.c \
			  index.c \
			  main.c \
			  mode.c \
			  radix_sort.c \
			  selection_sort.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
			  $(addprefix $(SRC_DIR)/$(OP_DIR)/, $(OP_FILES))

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
