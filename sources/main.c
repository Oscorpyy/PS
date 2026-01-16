/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:35:00 by opernod           #+#    #+#             */
/*   Updated: 2026/01/16 16:59:23 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"
#include "../../libft/libft.h"

static void	init_all(t_stack *stack, char **argv, int argc)
{
	stack->stack_a = args_to_int(argv, argc);
	stack->len_a = get_len_stack(argv, argc);
	stack->stack_b = ft_calloc(stack->len_a, sizeof(int));
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
	stack->print = 1;
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

static int	argc_updated(char **new_argv)
{
	int	i;

	i = 0;
	while (new_argv[i])
		i++;
	return (i);
}

static void	free_all(t_stack *stack, int i, char **final_argv, char	*joined)
{
	if (i == 1)
		ft_printf("Error\n", 2);
	if (stack->stack_a)
		free(stack->stack_a);
	if (stack->stack_b)
		free(stack->stack_b);
	if (final_argv)
		free_argv(final_argv, argc_updated(final_argv));
	if (joined)
		free(joined);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	char	**final_argv;
	char	*joined;
	int		new_argc;

	joined = strjoin_all(argc, argv, " ");
	if (!joined)
		return (1);
	final_argv = ft_split(joined, ' ');
	if (!final_argv)
	{
		free_all(&stack, 1, final_argv, joined);
		return (1);
	}
	new_argc = argc_updated(final_argv);
	init_all(&stack, final_argv, new_argc);
	if (!stack.stack_a || !stack.stack_b 
		|| only_one(&stack) != 0 || mode(argv, &stack) == 1)
	{
		free_all(&stack, 1, final_argv, joined);
		return (1);
	}
	free_all(&stack, 0, final_argv, joined);
	return (0);
}
