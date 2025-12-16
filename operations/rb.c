/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:19:30 by opernod           #+#    #+#             */
/*   Updated: 2025/12/16 13:29:39 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	rotate_b(int *stack_b, int len_b)
{
	int	i;
	int	temp;

	if (stack_b[0] == len_b)
		return ;
	i = 0;
	temp = stack_b[0];
	while (i + 1 != len_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i] = temp;
}
