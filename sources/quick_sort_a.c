/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:02:28 by azazel            #+#    #+#             */
/*   Updated: 2026/01/03 13:23:33 by azazel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static int	len_check(int len, t_stack *stack)
{
	if (len <= 1)
		return (1);
	else if (len == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			swap_a(stack);
		return (1);
	}
	return (0);
}

static void	loop_on_stack_a(int len, t_stack *stack, int *pushed, int *rotate)
{
	int	pivot;
	int	i;

	pivot = get_median_pivot(stack->stack_a, len);
	i = 0;
	while (i < len)
	{
		if (stack->stack_a[0] < pivot)
		{
			push_b(stack);
			*pushed += 1;
		}
		else
		{
			rotate_a(stack);
			*rotate += 1;
		}
		i++;
	}
}

void	quick_sort_a(t_stack *stack, int len)
{
	int	item_pushed;
	int	item_rotate;
	int	temp_rotate;

	if (is_sorted(stack->stack_a, len) == 0)
		return ;
	if (len_check(len, stack) == 1)
		return ;
	item_pushed = 0;
	item_rotate = 0;
	loop_on_stack_a(len, stack, &item_pushed, &item_rotate);
	if (item_rotate != stack->len_a)
	{
		temp_rotate = item_rotate;
		while (temp_rotate > 0)
		{
			reverse_rotate_a(stack);
			temp_rotate--;
		}
	}
	quick_sort_a(stack, item_rotate);
	quick_sort_b(stack, item_pushed);
}
