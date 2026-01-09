/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:35:00 by opernod           #+#    #+#             */
/*   Updated: 2026/01/09 14:46:42 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static int	*init_all(t_stack *stack, char **argv, int argc)
{
	int		*stack_a;

	stack_a = args_to_int(argv, argc);
	stack->len_a = get_len_stack(argv, argc);
	stack->len_b = 0;
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
	return (stack_a);
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

static void	free_all(t_stack *stack, int *stack_a, int i)
{
	if (i == 1)
		ft_printf("Error\n", 2);
	if (stack)
		free(stack);
	if (stack_a)
		free(stack_a);
	return ;
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	t_stack	*stack;
	int		stack_b[10000];
	char	**seperate_argv;

	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_printf("Error\n", 2);
		return (0);
	}
	seperate_argv = new_argv(argv, argc);
	stack_a = init_all(stack, seperate_argv, argc);
	stack->stack_a = stack_a;
	stack->stack_b = stack_b;
	if (!stack->stack_a || only_one(stack) != 0 || mode(argv, stack) == 1)
	{
		free_all(stack, stack_a, 1);
		return (0);
	}
	free_all(stack, stack_a, 0);
}
