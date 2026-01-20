/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:07:33 by opernod           #+#    #+#             */
/*   Updated: 2026/01/20 12:49:40 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

void	swap_b(t_stack *stack)
{
	int	tmp;

	if (stack->stack_b == NULL || stack->len_b < 2)
		return ;
	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
	stack->total++;
	stack->sb++;
	if (stack->total = 1)
		ft_printf("sb\n", 1);
}
