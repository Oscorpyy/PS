/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:03:28 by opernod           #+#    #+#             */
/*   Updated: 2025/12/17 18:11:28 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static int	push_min(t_stack *stack, int min, int bool, int total)
{
	if (bool == 1)
	{
		while (min != stack->stack_a[0])
		{
			rotate_a(stack);
			total++;
		}
	}
	else if (bool == 2)
	{
		while (min != stack->stack_a[0])
		{
			reverse_rotate_a(stack);
			total++;
		}
	}
	return (total);
}

static int	where_min(t_stack *stack, int total)
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
		total = push_min(stack, min, 1, total);
	else
		total = push_min(stack, min, 2, total);
	push_b(stack);
	total++;
	return (total);
}

int	selection_sort(t_stack *stack)
{
	int	total;

	total = 0;
	while (stack->len_a > 0)
		total = where_min(stack, total);
	while (stack->len_b > 0)
	{
		push_a(stack);
		total++;
	}
	return (total);
}
