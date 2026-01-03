/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:30:06 by azazel            #+#    #+#             */
/*   Updated: 2026/01/03 11:43:34 by azazel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	compare_execute_part_3(char *line, t_stack *stack)
{
	if (ft_strcmp(line, "sa\n") == 0)
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

static int	compare_execute_part_2(char *line, t_stack *stack)
{
	if (ft_strcmp(line, "rr\n") == 0)
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
	return (ERROR);
}

int	compare_execute(char *line, t_stack *stack)
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
	else if (compare_execute_part_2(line, stack) == 0)
		return (0);
	else if (compare_execute_part_3(line, stack) == 0)
		return (0);
	return (ERROR);
}
