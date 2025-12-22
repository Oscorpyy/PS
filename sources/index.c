/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:40:10 by lgoderne          #+#    #+#             */
/*   Updated: 2025/12/21 15:43:04 by azazel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static void sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;

    i = 0;
    while (i < size)
    {
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*indexation(t_stack *stack)
{
	int *temp_tab;
	int	i;
	int	j;

	temp_tab = malloc(sizeof(int) * stack->len_a);
	if (!temp_tab)
		return (NULL);
	i = -1;
	while (++i < stack->len_a)
		temp_tab[i] = stack->stack_a[i];
	sort_int_tab(temp_tab, stack->len_a);
	i = -1;
	while (++i < stack->len_a)
	{
		j = -1;
		while (j < stack->len_a)
		{
			if (stack->stack_a[i] == temp_tab[++j])
			{
				stack->stack_a[i] = j;
				break;
			}
		}
	}
	return (temp_tab);
}
