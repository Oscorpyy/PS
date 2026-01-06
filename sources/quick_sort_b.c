/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:02:55 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/06 12:29:18 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static int	len_check(int len, t_stack *stack)
{
	if (len == 0)
		return (1);
	if (len == 1)
	{
		push_a(stack);
		return (1);
	}
	else if (len == 2)
	{
		if (stack->stack_b[0] < stack->stack_b[1])
			swap_b(stack);
		push_a(stack);
		push_a(stack);
		return (1);
	}
	return (0);
}

static void	loop_on_stack_b(int len, t_stack *stack, int *pushed, int *rotate)
{
	int	pivot;
	int	i;

	pivot = get_median_pivot(stack->stack_b, len);
	i = 0;
	while (i < len)
	{
		if (stack->stack_b[0] > pivot)
		{
			push_a(stack);
			*pushed += 1;
		}
		else
		{
			rotate_b(stack);
			*rotate += 1;
		}
		i++;
	}
}

void	quick_sort_b(t_stack *stack, int len)
{
	int	item_pushed;
	int	item_rotate;
	int	temp_rotate;

	if (len_check(len, stack) == 1)
		return ;
	item_pushed = 0;
	item_rotate = 0;
	loop_on_stack_b(len, stack, &item_pushed, &item_rotate);
	if (item_rotate != stack->len_b)
	{
		temp_rotate = item_rotate;
		while (temp_rotate > 0)
		{
			reverse_rotate_b(stack);
			temp_rotate--;
		}
	}
	quick_sort_a(stack, item_pushed);
	quick_sort_b(stack, item_rotate);
}
