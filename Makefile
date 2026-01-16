# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 15:35:41 by opernod           #+#    #+#              #
#    Updated: 2026/01/16 12:10:05 by opernod          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I includes -I libft -I printf/includes

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

PRINTF_DIR	= printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a


SRC_DIR		= sources
OP_DIR		= operations
CHECKER_DIR	= checker

OP_FILES	= pa.c pb.c \
			  ra.c rb.c rr.c \
			  rra.c rrb.c rrr.c \
			  sa.c sb.c ss.c

SRC_FILES	= adaptive.c \
			  args_to_int.c \
			  bucket_sort.c \
			  disorder.c \
			  free_argv.c\
			  ft_atol.c \
			  ft_strcmp.c \
			  ft_strjoin_all.c \
			  index.c \
			  main.c \
			  mode.c \
			  quick_sort_a.c \
			  quick_sort_b.c \
			  quick_sort_utils.c \
			  quick_sort.c \
			  selection_sort.c \
			  

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
			  $(addprefix $(SRC_DIR)/$(OP_DIR)/, $(OP_FILES))

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT): $(LIBFT_OBJS)
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF): $(PRINTF_OBJS)
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	$(MAKE) -C $(CHECKER_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(CHECKER_DIR) clean


fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(CHECKER_DIR) fclean


re: fclean all

.PHONY: all clean fclean re bonus
