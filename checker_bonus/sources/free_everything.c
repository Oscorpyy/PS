/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:35:58 by opernod           #+#    #+#             */
/*   Updated: 2026/01/16 11:33:02 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"
#include "../includes/checker.h"

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

void	free_all(t_stack *stack, int i, char **final_argv, char	*joined)
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
