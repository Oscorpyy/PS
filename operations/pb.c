/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:14:04 by opernod           #+#    #+#             */
/*   Updated: 2025/12/16 13:58:03 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	push_b(int *stack_a, int *stack_b, int len_a, int len_b)
{
	int	i;

	if (stack_a == NULL || stack_b == NULL || len_a < 1)
		return ;
	i = len_b;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	i = 0;
	while (i < len_a - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
}
