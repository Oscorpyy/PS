/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 20:20:38 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/06 16:15:44 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/get_next_line.h"

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

static int	check_is_stack_sorted_stackb_empty(t_stack *stack, int *temp_stack)
{
	int	i;

	if (stack->len_b > 0)
	{
		ft_printf("KO\n", 1);
		return (1);
	}
	i = 0;
	while (i < stack->len_a - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
		{
			ft_printf("KO\n", 1);
			free_all(stack, temp_stack, 0);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	get_input(t_stack *stack, int *temp_stack)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		else if (compare_execute(line, stack) != 0)
		{
			ft_printf("Error\n", 2);
			free(line);
			get_next_line(-1);
			free_all(stack, temp_stack, 0);
			return (ERROR);
		}
		free(line);
	}
	return (0);
}

static int	check_argument(int argc, char **argv)
{
	if (argc < 2)
		return (ERROR);
	if (is_args_good(argv) == ERROR)
	{
		ft_printf("Error\n", 2);
		return (ERROR);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		*temp_stack;
	t_stack	*stack;
	int		stack_b[1000];

	if (check_argument(argc, argv) == ERROR)
		return (ERROR);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (ERROR);
	temp_stack = init_all(stack, argv, argc);
	stack->stack_b = stack_b;
	stack->stack_a = temp_stack;
	if (!stack->stack_a || only_one(stack) != 0)
	{
		free_all(stack, temp_stack, 1);
		return (ERROR);
	}
	if (get_input(stack, temp_stack) == ERROR)
		return (ERROR);
	if (check_is_stack_sorted_stackb_empty(stack, temp_stack) != 0)
		return (0);
	else
		ft_printf("OK\n", 1);
	free_all(stack, temp_stack, 0);
	return (0);
}
