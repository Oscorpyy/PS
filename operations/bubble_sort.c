/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:03:28 by opernod           #+#    #+#             */
/*   Updated: 2025/12/16 19:20:36 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"
// #include "../printf/includes/ft_printf.h"

void	ft_bubble_sort(t_stack *stack)
{
	int	total;

	total = 0;
	while (disorder(stack) > 0)
	{
		while(stack->len_a > 0)
		{
			if (stack->stack_a[0] > stack->stack_a[1])
			{
				swap_a(stack);
				printf("sa\n");
				total++;
			}
			push_b(stack);
			printf("pb\n");
			total++;
		}
		while (stack->len_b > 0)
		{
			push_a(stack);
			printf("pa\n");
			total++;
		}
	}
	printf("\n %i \n", total);
}

