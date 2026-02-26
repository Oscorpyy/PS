/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:05:30 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/06 12:28:30 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static void	bubble_sort(int len, int *tab)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_median_pivot(int *stack_tab, int len)
{
	int	*tab;
	int	i;
	int	tmp;

	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (0);
	i = -1;
	while (++i < len)
		tab[i] = stack_tab[i];
	bubble_sort(len, tab);
	tmp = tab[len / 2];
	free(tab);
	return (tmp);
}

int	is_sorted(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] > stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}
