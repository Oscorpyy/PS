/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:22:00 by opernod           #+#    #+#             */
/*   Updated: 2025/12/17 18:01:25 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	reverse_rotate_b(t_stack *stack)
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
	printf("rrb\n");
}
