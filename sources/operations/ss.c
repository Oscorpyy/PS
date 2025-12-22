/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:07:57 by opernod           #+#    #+#             */
/*   Updated: 2025/12/21 15:47:42 by azazel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

static void	sa(t_stack *stack)
{
	int	tmp;

	if (stack->stack_a == NULL || stack->len_a < 2)
		return ;
	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
}

static void	sb(t_stack *stack)
{
	int	tmp;

	if (stack->stack_b == NULL || stack->len_b < 2)
		return ;
	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
}

void	swap_s(t_stack *stack)
{
	sa(stack);
	sb(stack);
	stack->total++;
	stack->ss++;
	printf("ss\n");
}
