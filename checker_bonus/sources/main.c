/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 20:20:38 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/20 12:52:27 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/get_next_line.h"
#include "../../libft/libft.h"

static int	check_is_stack_sorted_stackb_empty(t_stack *stack)
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
			return (1);
		}
		i++;
	}
	return (0);
}

static int	get_input(t_stack *stack)
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

static int	input_and_check(t_stack *stack, char **final_argv, char	*joined)
{
	if (!stack->stack_a || only_one(stack) != 0)
	{
		free_all(stack, 1, final_argv, joined);
		return (ERROR);
	}
	if (get_input(stack) == ERROR)
	{
		free_all(stack, 0, final_argv, joined);
		return (ERROR);
	}
	if (check_is_stack_sorted_stackb_empty(stack) != 0)
	{
		free_all(stack, 0, final_argv, joined);
		return (ERROR);
	}
	else
		ft_printf("OK\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	char	**final_argv;
	char	*joined;

	joined = strjoin_all(argc, argv, " ");
	if (!joined)
		return (1);
	final_argv = ft_split(joined, ' ');
	if (!final_argv)
	{
		free_all(&stack, 1, final_argv, joined);
		return (1);
	}
	init_all(&stack, final_argv, argc);
	if (!stack.stack_a || !stack.stack_b
		|| check_argument(argc, final_argv) == ERROR)
	{
		free_all(&stack, 1, final_argv, joined);
		return (1);
	}
	if (input_and_check(&stack, final_argv, joined) != 0)
		return (1);
	free_all(&stack, 0, final_argv, joined);
	return (0);
}
