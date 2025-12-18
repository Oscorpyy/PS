/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:26:53 by opernod           #+#    #+#             */
/*   Updated: 2025/12/18 16:52:38 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int *read_file_to_array(const char *filename, int *size);

static void init_all(t_stack *stack)
{
	stack->pa = 0;
	stack->pb = 0;
	stack->ra = 0;
	stack->rb = 0;
	stack->rr = 0;
	stack->rra = 0;
	stack->rrb = 0;
	stack->rrr = 0;
	stack->sa = 0;
	stack->sb = 0;
	stack->ss = 0;
	stack->total = 0;
}

int	main(void)
{
	int 	size;
	int 	*stack_a;
	int		stack_b[500] = {};
	int		i;
	float	disorder_per;

	t_stack *stack = malloc(sizeof(t_stack));
	stack_a = read_file_to_array("args.txt", &size);
	stack->stack_a = stack_a;
	stack->stack_b = stack_b;
	stack->len_a = 500;
	stack->len_b = 0;
	init_all(stack);
	i = 0;
	
	disorder_per = disorder(stack);
 	selection_sort(stack);
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
	printf("\ndisorder = %f%%\n", (disorder_per)*100);
	printf("total operation = %i", stack->total);
}
