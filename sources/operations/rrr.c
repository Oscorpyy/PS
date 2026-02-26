/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:22:06 by opernod           #+#    #+#             */
/*   Updated: 2026/01/20 13:06:26 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

static void	rra(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->stack_a == NULL || stack->len_a < 2)
		return ;
	i = stack->len_a - 1;
	temp = stack->stack_a[i];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = temp;
}

static void	rrb(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->stack_b == NULL || stack->len_b < 2)
		return ;
	i = stack->len_b - 1;
	temp = stack->stack_b[i];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = temp;
}

void	reverse_rotate_r(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	stack->total++;
	stack->rrr++;
	if (stack->print == 1)
		ft_printf("rrr\n", 1);
}
