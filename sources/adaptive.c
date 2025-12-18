/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:46:46 by opernod           #+#    #+#             */
/*   Updated: 2025/12/18 13:04:09 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	adaptive_algo(t_stack *stack)
{
	float	numdis;

	numdis = disorder(stack);
	if (numdis < 0.2)
		selection_sort(stack);
	else if(0.2 <= numdis && numdis < 0.5)
		bucket_sort_simple(stack);
	else
		radix(stack);
}

int	benchmode(t_stack *stack)
{
	float	numdis;

	numdis = disorder(stack);
	if (numdis < 0.2)
		stack->total = selection_sort(stack);
	else if(0.2 <= numdis && numdis < 0.5)
		stack->total = bucket_sort_simple(stack);
	else
		stack->total = radix(stack);
	return (stack->total);
}