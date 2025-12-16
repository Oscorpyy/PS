/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:15:02 by opernod           #+#    #+#             */
/*   Updated: 2025/12/16 13:29:20 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	rotate_a(int *stack_a, int len_a)
{
	int	i;
	int	temp;

	if (stack_a[0] == len_a)
		return ;
	i = 0;
	temp = stack_a[0];
	while (i + 1 != len_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = temp;
}
