/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:35:58 by opernod           #+#    #+#             */
/*   Updated: 2026/01/12 15:36:23 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

void	free_argv(char **new_argv, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(new_argv[i]);
		i++;
	}
	free(new_argv);
}

void	free_all(t_stack *stack, int *stack_a, int i)
{
	if (i == 1)
		ft_printf("Error\n", 2);
	if (stack)
		free(stack);
	if (stack_a)
		free(stack_a);
	return ;
}
