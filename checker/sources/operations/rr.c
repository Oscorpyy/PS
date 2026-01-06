/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:19:43 by opernod           #+#    #+#             */
/*   Updated: 2026/01/06 12:14:04 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

static void	ra(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->stack_a == NULL || stack->len_a < 2)
		return ;
	i = 0;
	temp = stack->stack_a[0];
	while (i + 1 != stack->len_a)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i] = temp;
}

static void	rb(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->stack_b == NULL || stack->len_b < 2)
		return ;
	i = 0;
	temp = stack->stack_b[0];
	while (i + 1 != stack->len_b)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i] = temp;
}

void	rotate_r(t_stack *stack)
{
	ra(stack);
	rb(stack);
	stack->total++;
	stack->rr++;
}
