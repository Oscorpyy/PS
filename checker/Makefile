# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/23 01:26:23 by azazel            #+#    #+#              #
#    Updated: 2025/12/26 16:58:00 by azazel           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I includes -I libft -I printf/includes

LIBFT_DIR	= ../libft
LIBFT		= $(LIBFT_DIR)/libft.a

PRINTF_DIR	= ../printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

SRC_DIR		= sources
OP_DIR		= ../sources/operations

# Operations files located in sources/operations
OP_FILES	= pa.c pb.c \
			  ra.c rb.c rr.c \
			  rra.c rrb.c rrr.c \
			  sa.c sb.c ss.c

# Main source files located in sources/
SRC_FILES	= main.c \
			  args_parser.c \
			  stack_init.c \
			  ft_atol.c \
			  get_next_line.c \
			  get_next_line_utils.c \
			  ft_strcmp.c
			  
SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
			  $(addprefix $(OP_DIR)/, $(OP_FILES))

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME) -g

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re