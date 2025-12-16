/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:26:53 by opernod           #+#    #+#             */
/*   Updated: 2025/12/16 14:02:15 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int	main(void)
{
	int	i;
	int	stack_a[10] = {-9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	len_a;
	int	stack_b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	len_b;

	len_a = 10;
	len_b = 10;
	swap_s(stack_a, stack_b, len_a, len_b);
	i = 0;
	while (i != len_a)
	{
		printf("stack_a[%i] = %i ", i, stack_a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i != len_b)
	{
		printf("stack_b[%i] = %i ", i, stack_b[i]);
		i++;
	}
	printf("\n");
}
