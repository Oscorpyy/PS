/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:20:25 by opernod           #+#    #+#             */
/*   Updated: 2025/12/16 13:51:57 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	reverse_rotate_a(int *stack_a, int len)
{
	int	i;
	int	temp;

	if (stack_a == NULL || len < 2)
		return ;
	i = len - 1;
	temp = stack_a[i];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = temp;
}
