/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:26:53 by opernod           #+#    #+#             */
/*   Updated: 2025/12/17 14:22:38 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"


int	main(void)
{
	int		stack_b[500] = {};
	int		i;
	int		fd;
	int		total;
	float	disorder_per;
	t_stack *stack = malloc(sizeof(t_stack));
	stack->stack_a = stack_a;
	stack->stack_b = stack_b;
	stack->len_a = 500;
	stack->len_b = 0;
	i = 0;

	fd = open(args.txt, O_RDONLY);



	
	disorder_per = disorder(stack);
	total = selection_sort(stack);
	while (i != stack->len_a)
	{
		printf("stack_a[%i] = %i \n", i, stack->stack_a[i]);
		i++;
	}
	i = 0;
	while (i != stack->len_b)
	{
		printf("stack_b[%i] = %i \n", i, stack->stack_b[i]);
		i++;
	}
	printf("\ndisorder = %f%%\n", disorder_per);
	printf("total operation = %i", total);
}
