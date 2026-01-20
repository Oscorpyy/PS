/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:08:30 by opernod           #+#    #+#             */
/*   Updated: 2026/01/20 12:49:07 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

void	push_a(t_stack *stack)
{
	int	i;

	if (stack->stack_a == NULL || stack->stack_b == NULL || stack->len_b < 1)
		return ;
	i = stack->len_a;
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = stack->stack_b[0];
	i = 0;
	while (i < stack->len_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->len_a++;
	stack->len_b--;
	stack->pa++;
	stack->total++;
	if (stack->total = 1)
		ft_printf("pa\n", 1);
}
