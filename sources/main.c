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

static int	*init_all(t_stack *stack, char **argv, int argc)
{
	int		*stack_a;
	int		stack_b[1000];

	stack_a = args_to_int(argv, argc);
	stack->stack_b = stack_b;
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

void	free_all(t_stack *stack, int i)
{
	if (i == 1)
		ft_printf("Error\n");
	if (stack)
		free(stack);
	return ;
}

int	main(int argc, char **argv)
{
	int		i;
	int		*stack_a;
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_printf("Error\n");
		return (0);
	}
	stack_a = init_all(stack, argv, argc);
	stack->stack_a = stack_a;
	ft_printf("disorder before sort : %f\n", disorder(stack));
	if (!stack->stack_a || only_one(stack) != 0 || mode(argv, stack) == 1)
	{
		free_all(stack, 1);
		return (0);
	}
	i = 0;
	while (i < stack->len_a)
	{
		ft_printf("stack[%i] = %i \n", i, stack->stack_a[i]);
		i++;
	}
	ft_printf("disorder after sort : %f\n", disorder(stack));
	free(stack_a);
	free_all(stack, 0);
}
