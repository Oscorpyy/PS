/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:35:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/18 13:09:13 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int *read_file_to_array(const char *filename, int *size);

static void	init_all(t_stack *stack)
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

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		stack_b[500];
	int		i;
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack_a = args_to_int(argv, argc);
	stack->stack_a = stack_a;
	stack->stack_b = stack_b;
	stack->len_a = 5;
	stack->len_b = 0;
	init_all(stack);
	i = 0;
	mode(argv, stack);
	if (!stack->stack_a)
	{
		printf("abuse frr on as dit un int");
		return (0);
	}
	while (i != argc - 1)
	{
		printf("stack[%i] = %i \n", i, stack->stack_a[i]);
		i++;
	}
	printf("disorder = %f\n", disorder(stack));
	free(stack);
	free(stack_a);
}
