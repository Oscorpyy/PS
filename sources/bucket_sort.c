/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:27:04 by lgoderne          #+#    #+#             */
/*   Updated: 2025/12/18 14:55:48 by opernod          ###   ########lyon.fr   */
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
	little = 0;
	big = nb;
	while (little < big)
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
	int	num_buckets = ft_sqrt(stack.len_a);

	
}