/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:03:28 by opernod           #+#    #+#             */
/*   Updated: 2025/12/18 16:51:59 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static void	push_min(t_stack *stack, int min, int bool)
{
	if (bool == 1)
	{
		while (min != stack->stack_a[0])
			rotate_a(stack);
	}
	else if (bool == 2)
	{
		while (min != stack->stack_a[0])
			reverse_rotate_a(stack);
	}
}

static void	where_min(t_stack *stack)
{
	int	min;
	int	i;

	i = 0;
	min = stack->stack_a[i];
	while (i < stack->len_a)
	{
		if (stack->stack_a[i] < min)
			min = stack->stack_a[i];
		i++;
	}
	i = 0;
	while (stack->stack_a[i] != min)
		i++;
	if (stack->len_a - i > i)
		push_min(stack, min, 1);
	else
		push_min(stack, min, 2);
	push_b(stack);
}

void	selection_sort(t_stack *stack)
{
	while (stack->len_a > 0)
		where_min(stack);
	while (stack->len_b > 0)
		push_a(stack);
}
