/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:14:04 by opernod           #+#    #+#             */
/*   Updated: 2026/01/06 16:16:37 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

void	push_b(t_stack *stack)
{
	int	i;

	if (stack->stack_a == NULL || stack->stack_b == NULL || stack->len_a < 1)
		return ;
	i = stack->len_b;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = stack->stack_a[0];
	i = 0;
	while (i < stack->len_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->len_a--;
	stack->len_b++;
	stack->total++;
	stack->pb++;
	ft_printf("pb\n", 1);
}
