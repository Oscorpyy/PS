/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 20:20:38 by azazel            #+#    #+#             */
/*   Updated: 2025/12/27 00:05:33 by azazel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/checker.h"
#include "../includes/get_next_line.h"
#include "../../libft/libft.h"

static void	free_all(t_stack *stack, int* stack_a, int i) 
{
	if (i == 1)
		ft_printf("Error\n");
	if (stack)
		free(stack);
	if (stack_a)
		free(stack_a);
	return ;
}

static int	compare_execute(char *line, t_stack *stack)
{
	if (ft_strcmp(line, "pa\n") == 0)
	{
		push_a(stack);
		return (0);
	}
	else if (ft_strcmp(line, "pb\n") == 0)
	{
		push_b(stack);
		return (0);
	}
	else if (ft_strcmp(line, "ra\n") == 0)
	{
		rotate_a(stack);
		return (0);
	}
	else if (ft_strcmp(line, "rb\n") == 0)
	{
		rotate_b(stack);
		return (0);
	}
	else if (ft_strcmp(line, "rr\n") == 0)
	{
		rotate_r(stack);
		return (0);
	}
	else if (ft_strcmp(line, "rra\n") == 0)
	{
		reverse_rotate_a(stack);
		return (0);
	}
	else if (ft_strcmp(line, "rrb\n") == 0)
	{
		reverse_rotate_b(stack);
		return (0);
	}
	else if (ft_strcmp(line, "rrr\n") == 0)
	{
		reverse_rotate_r(stack);
		return (0);
	}
	else if (ft_strcmp(line, "sa\n") == 0)
	{
		swap_a(stack);
		return (0);
	}
	else if (ft_strcmp(line, "sb\n") == 0)
	{
		swap_b(stack);
		return (0);
	}
	else if (ft_strcmp(line, "ss\n") == 0)
	{
		swap_s(stack);
		return (0);
	}
	return (ERROR);	
}

int	main(int argc, char **argv)
{
	int		*temp_stack;
	t_stack	*stack;
	char	*line;
	int		i;

	if (argc < 2)
		return (0);
	if (is_args_good(argv) == ERROR)
	{
		ft_printf("Error");
		return (ERROR);
	}
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (ERROR);
	temp_stack = init_all(stack, argv, argc);
	stack->stack_a = temp_stack;
	if (!stack->stack_a || only_one(stack) != 0)
	{
		free_all(stack, temp_stack, 1);
		return (ERROR);
	}
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			 break;
		else if (compare_execute(line, stack) != 0)
		{
			ft_printf("Error");
			free(line);
			get_next_line(-1);
			free_all(stack, temp_stack, 0);
			return (ERROR);
		}
		free(line);
	}
	// get_next_line(-1);
	for (int i = 0; i < stack->len_a; i++) // leeeee deeeeeebuuuuuuug
	{
		ft_printf("stack[%i]: %i\n", i, stack->stack_a[i]);
	}
	
	i = 0;
	while (i < stack->len_a - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
		{
			ft_printf("KO");
			free_all(stack, temp_stack, 0);
			return (0);
		}
		i++;
	}
	ft_printf("OK");
	free_all(stack, temp_stack, 0);
	return (0);
}
