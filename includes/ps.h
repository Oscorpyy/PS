/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:46:37 by lgoderne          #+#    #+#             */
/*   Updated: 2025/12/18 18:07:20 by opernod          ###   ########lyon.fr   */
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

int		bucket_sort_simple(t_stack *stack);
int		*args_to_int(char **str, int strlen);
int		ft_strcmp(const char *s1, const char *s2);
long	ft_atol(const char *str);
void	radix(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_s(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_r(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_r(t_stack *stack);
void	selection_sort(t_stack *stack);
void	mode(char	**str, t_stack *stack);
void	benchmode(t_stack *stack, char *mode);
char	*adaptive_algo(t_stack *stack);
float	disorder(t_stack *stack);

#endif
