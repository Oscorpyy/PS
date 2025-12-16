/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:07:33 by opernod           #+#    #+#             */
/*   Updated: 2025/12/16 13:55:16 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	swap_b(int *stack_b, int len)
{
	int	tmp;

	if (stack_b == NULL || len < 2)
		return ;
	tmp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = tmp;
}
