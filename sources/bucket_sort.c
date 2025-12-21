/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:27:04 by lgoderne          #+#    #+#             */
/*   Updated: 2025/12/21 13:50:19 by azazel           ###   ########lyon.fr   */
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

static int get_max_pos(t_stack *stack, int to_find)
{
	int	i;

	i = 0;
	while (i < stack->len_b)
	{
		if (stack->stack_b[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

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

static int	*indexation(t_stack *stack)
{
	int	*ranked_tab;
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
	i = 0;
	while (i < stack->len_a)
	{
		j = 0;
		while (j < stack->len_a)
		{
			if (stack->stack_a[i] == temp_tab[j])
			{
				stack->stack_a[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
	return (temp_tab);
}

int	bucket_sort_simple(t_stack *stack)
{
	int	i;
	int	range;
	int	max;
	int	max_pos;
	int	*tmp_tab;

	tmp_tab = indexation(stack);
	range = ft_sqrt(stack->len_a);
	i = 0;
	while (stack->len_a > 0)
	{
		if (stack->stack_a[0] <= i)
		{
			push_b(stack);
			rotate_b(stack);
			i++;
		}
		else if (stack->stack_a[0] <= i + range)
		{
			push_b(stack);
			i++;
		}
		else
			rotate_a(stack);
	}
	while (stack->len_b > 0)
	{
		max = stack->len_b - 1;
		max_pos = get_max_pos(stack, max);
		if (max_pos == 0)
			push_a(stack);
		else if (max_pos <= stack->len_b / 2)
			rotate_b(stack);
		else
			reverse_rotate_b(stack);
	}
	i = 0;
	while (i < stack->len_a)
	{
		stack->stack_a[i] = tmp_tab[stack->stack_a[i]];
		i++;
	}
	free(tmp_tab);
	return (0);
}
