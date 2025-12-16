/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:36:52 by lgoderne          #+#    #+#             */
/*   Updated: 2025/12/16 13:54:53 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	swap_a(int *stack_a, int len)
{
	int	tmp;

	if (stack_a == NULL || len < 2)
		return ;
	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;
}
