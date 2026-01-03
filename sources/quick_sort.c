/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:30:42 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/03 13:01:19 by azazel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	quick_sort(t_stack *stack)
{
	int	*tmp_stack;

	tmp_stack = indexation(stack);
	if (!tmp_stack)
		return ;
	quick_sort_a(stack, stack->len_a);
}
