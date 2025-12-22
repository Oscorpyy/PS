/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:35:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/21 15:22:00 by azazel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

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

static int	only_one(t_stack *stack)
{
	int	error;
	int	i;
	int	j;

	error = 0;
	i = 0;
	while (i < stack->len_a)
	{
		j = i + 1;
		while (j < stack->len_a)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
				error++;
			j++;
		}
		i++;
	}
	return (error);
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
	stack->len_a = 1;
	stack->len_b = 0;
	init_all(stack);
	if (!stack->stack_a || only_one(stack) != 0)
	{
		ft_printf("Error\n");
		if (stack)
			free(stack);
		if (stack)
			free(stack_a);
		return (0);
	}
	ft_printf("disorder = %f\n", disorder(stack));
	mode(argv, stack);
	i = 0;
	while (i < stack->len_a)
	{
		ft_printf("stack[%i] = %i \n", i, stack->stack_a[i]);
		i++;
	}
	if (stack)
		free(stack);
	if (stack)
		free(stack_a);
}
