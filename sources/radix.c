/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:01:21 by lgoderne          #+#    #+#             */
/*   Updated: 2025/12/18 16:31:26 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static int	calc_max_bits(t_stack *stack)
{
	int	i;
	int	max;
	int	max_bits;

	max = stack->stack_a[0];
	i = 1;
	while (i < stack->len_a)
	{
		if (max < stack->stack_a[i])
			max = stack->stack_a[i];
		i++;
	}
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	compare(t_stack *stack, int i)
{
	if (((stack->stack_a[0] >> i) & 1) == 0)
		push_b(stack);
	else
	{
		rotate_a(stack);
		stack->stack_a += 1;
	}
}

int	radix(t_stack *stack)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	max_bits = calc_max_bits(stack);
	i = 0;
	while (i++ < max_bits)
	{
		size = stack->len_a;
		j = 0;
		while (j++ < size)
			compare(stack, i);
		while (stack->len_b > 0)
		{
			push_a(stack);
			stack->total += 1;
		}
	}
	return (0);
}
