# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 15:35:41 by opernod           #+#    #+#              #
#    Updated: 2026/01/16 17:36:57 by opernod          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS		= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

PRINTF_DIR	= printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

PRINTF_FLAGS = -Wall -Wextra -Werror
PRINTF_INCLUDES = -I $(PRINTF_DIR)/includes

PRINTF_FILES = ft_printf.c ft_putall.c
PRINTF_SRCS	= $(addprefix $(PRINTF_DIR)/sources/, $(PRINTF_FILES))
PRINTF_OBJS	= $(PRINTF_SRCS:.c=.o)

SRC_DIR		= sources
OP_DIR		= operations
CHECKER_DIR	= checker
CHECKER_SRC	= $(CHECKER_DIR)/sources
CHECKER_OP	= $(CHECKER_DIR)/sources/operations

PS_OP_FILES	= pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c sa.c sb.c ss.c

PS_SRC_FILES	= adaptive.c \
				  args_to_int.c \
				  bucket_sort.c \
				  disorder.c \
				  free_argv.c \
				  ft_atol.c \
				  ft_strcmp.c \
				  ft_strjoin_all.c \
				  index.c \
				  main.c \
				  mode.c \
				  quick_sort.c \
				  quick_sort_a.c \
				  quick_sort_b.c \
				  quick_sort_utils.c \
				  selection_sort.c

CHECKER_SRC_FILES = argc_update.c \
					 args_parser.c \
					 compare_execute.c \
					 free_everything.c \
					 ft_atol.c \
					 ft_strcmp.c \
					 ft_strjoin_all.c \
					 get_next_line.c \
					 get_next_line_utils.c \
					 main.c \
					 stack_init.c

PS_SRCS		= $(addprefix $(SRC_DIR)/, $(PS_SRC_FILES)) \
			  $(addprefix $(SRC_DIR)/$(OP_DIR)/, $(PS_OP_FILES))

CHECKER_SRCS = $(addprefix $(CHECKER_SRC)/, $(CHECKER_SRC_FILES)) \
			   $(addprefix $(CHECKER_OP)/, $(PS_OP_FILES))

PS_OBJS		= $(PS_SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(PS_OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) -I includes -I $(LIBFT_DIR) -I $(PRINTF_DIR)/includes $(PS_OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "✓ push_swap created"

$(BONUS): $(CHECKER_OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) -I $(CHECKER_DIR)/includes -I $(LIBFT_DIR) -I $(PRINTF_DIR)/includes $(CHECKER_OBJS) $(LIBFT) $(PRINTF) -o $(BONUS)
	@echo "✓ checker created"

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(PRINTF): $(PRINTF_OBJS)
	@ar -rcs $(PRINTF) $(PRINTF_OBJS)
	@echo "✓ printf created"

$(PRINTF_DIR)/sources/%.o : $(PRINTF_DIR)/sources/%.c $(PRINTF_DIR)/includes/ft_printf.h
	@$(CC) $(PRINTF_FLAGS) $(PRINTF_INCLUDES) -c $< -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -I includes -I $(LIBFT_DIR) -I $(PRINTF_DIR)/includes -c $< -o $@

clean:
	@$(RM) $(PS_OBJS) $(CHECKER_OBJS) $(PRINTF_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "✓ Objects cleaned"

fclean: clean
	@$(RM) $(NAME) $(BONUS) $(PRINTF)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "✓ All cleaned"

re: fclean all

FORCE:

.PHONY: all bonus clean fclean re 