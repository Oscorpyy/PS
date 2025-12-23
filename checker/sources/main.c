/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 20:20:38 by azazel            #+#    #+#             */
/*   Updated: 2025/12/23 22:48:48 by azazel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/ps.h"
#include "../includes/checker.h"

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

// pas oublier de check si doublons et si c'est plus grand que un int
int	main(int argc, char **argv)
{
	int	*temp_stack;
	t_stack	*stack;

	if (argc < 2)
		return (0);
	if (is_args_good(argv) == ERROR)
	{
		ft_printf("Error");
		return (-1);
	}
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (1);
	temp_stack = init_all(stack, argv, argc);
	stack->stack_a = temp_stack;
	if (!stack->stack_a || only_one(stack) != 0)
	{
		free_all(stack, temp_stack, 1);
		return (-1);
	}
	ft_printf("stack %i", stack->stack_a[0]);
	return (0);
}
