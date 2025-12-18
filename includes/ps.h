/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:46:37 by lgoderne          #+#    #+#             */
/*   Updated: 2025/12/18 13:09:21 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	len_a;
	int	len_b;
	int	pa;	
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	sa;
	int	sb;
	int	ss;
	int	total;
}	t_stack;

int		*args_to_int(char **str, int strlen);
long	ft_atol(const char *str);
int		radix(t_stack *stack);
int		selection_sort(t_stack *stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_s(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_r(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_r(t_stack *stack);
float	disorder(t_stack *stack);
void	ft_bubble_sort(t_stack *stack);
void	bubble_sort_push_swap(t_stack *stack);
int		get_index(t_stack *stack, int value, int len);
int		get_chunk_size(int size);
void	push_all_back(t_stack *stack, int *total);

#endif
