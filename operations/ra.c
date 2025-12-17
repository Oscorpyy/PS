/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:15:02 by opernod           #+#    #+#             */
/*   Updated: 2025/12/16 16:26:36 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	rotate_a(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->stack_a[0] == stack->len_a)
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
