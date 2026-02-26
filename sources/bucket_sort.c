/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:27:04 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/07 10:43:54 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i * i <= nb && i <= 46340)
		i++;
	return (i - 1);
}

static int	get_max_pos(t_stack *stack, int to_find)
{
	int	i;

	i = 0;
	while (i < stack->len_b)
	{
		if (stack->stack_b[i] == to_find)
			return (i);
		i++;
	}
	return (stack->len_a / 2);
}

static void	loop_stack_a(t_stack *stack, int range)
{
	int	i;

	i = 0;
	while (stack->len_a > 0)
	{
		if (stack->stack_a[0] <= i)
		{
			push_b(stack);
			rotate_b(stack);
			i++;
		}
		else if (stack->stack_a[0] <= i + range)
		{
			push_b(stack);
			i++;
		}
		else
			rotate_a(stack);
	}
}

void	loop_stack_b(t_stack *stack)
{
	int	max;
	int	max_pos;

	while (stack->len_b > 0)
	{
		max = stack->len_b - 1;
		max_pos = get_max_pos(stack, max);
		if (max_pos == 0)
			push_a(stack);
		else if (max_pos <= stack->len_b / 2)
			rotate_b(stack);
		else
			reverse_rotate_b(stack);
	}
}

void	bucket_sort_simple(t_stack *stack)
{
	int	range;
	int	*tmp_tab;

	if (disorder(stack) == 0)
		return ;
	tmp_tab = indexation(stack);
	range = ft_sqrt(stack->len_a);
	loop_stack_a(stack, range);
	loop_stack_b(stack);
	free(tmp_tab);
}
