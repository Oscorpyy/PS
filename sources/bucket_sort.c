/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:27:04 by lgoderne          #+#    #+#             */
/*   Updated: 2025/12/18 18:54:44 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static int	ft_sqrt(int nb)
{
	int			little;
	long long	mid;
	int			big;

	if (nb < 1)
		return (0);
	little = 1;
	big = nb;
	if (nb == 1)
		return (1);
	while (little <= big)
	{
		mid = (little + big) / 2;
		if (mid < nb)
			little = mid + 1;
		else if (mid * mid > nb)
			big = mid - 1;
		else
			return ((int)mid);
	}
	return (0);
}

int	bucket_sort_simple(t_stack *stack)
{
	int	i;
	int	range;
	int	max;
	
	range = ft_sqrt(stack->len_a);
	i = 0;
	while (stack->len_a > 0)
	{
		if (stack->stack_a[0] <= stack->stack_a[i])
		{
			push_b(stack);
			rotate_b(stack);
			i++;
		}
		else if (stack->stack_a[0] <= stack->stack_a[i + range])
		{
			push_b(stack);
			i++;
		}
		else
			rotate_a(stack);
	}
	while (stack->len_b > 0) // a opti
	{
		max = get_max(stack);
		if (stack->stack_b[0] == max)
			push_a(stack);
		else
			rotate_b(stack);
	}
	return (0);
}
