/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:30:42 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/07 10:44:31 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	quick_sort(t_stack *stack)
{
	int	*tmp_stack;

	if (disorder(stack) == 0)
		return ;
	tmp_stack = indexation(stack);
	if (!tmp_stack)
		return ;
	quick_sort_a(stack, stack->len_a);
	free(tmp_stack);
}
