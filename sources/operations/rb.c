/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:19:30 by opernod           #+#    #+#             */
/*   Updated: 2026/01/05 14:48:10 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

void	rotate_b(t_stack *stack)
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
	stack->total++;
	stack->rb++;
	ft_printf("rb\n", 1);
}
