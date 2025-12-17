/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:51:07 by lgoderne          #+#    #+#             */
/*   Updated: 2025/12/16 19:20:08 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

float	disorder(t_stack *stack)
{
	float	mistakes;
	float	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < stack->len_a - 1)
	{
		j = i + 1;
		while (j < stack->len_a - 1)
		{
			total_pairs += 1;
			if (stack->stack_a[i] > stack->stack_a[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
