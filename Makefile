# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 15:35:41 by opernod           #+#    #+#              #
#    Updated: 2026/01/07 14:11:32 by opernod          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I includes -I libft -I printf/includes

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_SRCS	= $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJS	= $(LIBFT_SRCS:.c=.o)

PRINTF_DIR	= printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a
PRINTF_SRCS	= $(wildcard $(PRINTF_DIR)/sources/*.c)
PRINTF_OBJS	= $(PRINTF_SRCS:.c=.o)

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
			  ft_atol.c \
			  ft_strcmp.c \
			  index.c \
			  main.c \
			  mode.c \
			  new_argv.c \
			  quick_sort.c \
			  quick_sort_a.c \
			  quick_sort_b.c \
			  quick_sort_utils.c \
			  selection_sort.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
			  $(addprefix $(SRC_DIR)/$(OP_DIR)/, $(OP_FILES))

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME) -g

$(LIBFT): $(LIBFT_OBJS)
	ar rcs $(LIBFT) $(LIBFT_OBJS)

$(PRINTF): $(PRINTF_OBJS)
	ar rcs $(PRINTF) $(PRINTF_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

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
