/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:46:37 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/09 14:45:11 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

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

int		*indexation(t_stack *stack);
int		mode(char	**str, t_stack *stack);
int		*args_to_int(char **str, int strlen);
int		ft_printf(const char *to_print, int fd, ...);
int		benchmode(t_stack *stack, char *mode);
int		get_len_stack(char	**str, int len_str);
int		ft_strcmp(const char *s1, const char *s2);
int		is_sorted(int *stack, int len);
int		get_median_pivot(int *stack_tab, int len);
long	ft_atol(const char *str);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_s(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_r(t_stack *stack);
void	quick_sort(t_stack *stack);
void	quick_sort_a(t_stack *stack, int len);
void	quick_sort_b(t_stack *stack, int len);
void	radix_sort(t_stack *stack);
void	selection_sort(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_r(t_stack *stack);
void	bucket_sort_simple(t_stack *stack);
char	*adaptive_algo(t_stack *stack);
char	**new_argv(char **argv, int argc);
float	disorder(t_stack *stack);

#endif
