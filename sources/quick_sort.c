/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:30:42 by azazel            #+#    #+#             */
/*   Updated: 2026/01/02 15:51:58 by azazel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static void	quick_sort_a(t_stack *stack, int len);

static int  get_median_pivot(int *stack_tab, int len)
{
	int	*tab;
	int	i;
	int	j;
	int	tmp;

	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (0);
	i = -1;
	while (++i < len)
		tab[i] = stack_tab[i];
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
	tmp = tab[len / 2];
	free(tab);
	return (tmp);
}

static int	is_sorted(int *stack, int len)
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

static void	quick_sort_b(t_stack *stack, int len)
{
	int	i;
	int	pivot;
	int	item_pushed;
	int	item_rotate;
	int	temp_rotate;

	pivot = get_median_pivot(stack->stack_b, len);
	item_pushed = 0;
	item_rotate = 0;
	if (len == 0)
		return ;
	if (len == 1)
	{
		push_a(stack);
		return;
	}
	else if (len == 2)
	{
		if (stack->stack_b[0] < stack->stack_b[1])
			swap_b(stack);
		push_a(stack);
		push_a(stack);
		return ;
	}
	i = 0;
	while (i < len)
	{
		if (stack->stack_b[0] > pivot)
		{
			push_a(stack);
			item_pushed++;
		}
		else
		{
			rotate_b(stack);
			item_rotate++;
		}
		i++;
	}
	if (item_rotate != stack->len_b)
	{
		temp_rotate = item_rotate;
		while (temp_rotate > 0)
		{
			reverse_rotate_b(stack);
			temp_rotate--;
		}
	}
	quick_sort_a(stack, item_pushed);
	quick_sort_b(stack, item_rotate);
}

static void	quick_sort_a(t_stack *stack, int len)
{
	int	i;
	int	pivot;
	int	item_pushed;
	int	item_rotate;
	int	temp_rotate;

	if (is_sorted(stack->stack_a, len) == 0)
		return ;
	pivot = get_median_pivot(stack->stack_a, len);
	item_pushed = 0;
	item_rotate = 0;
	if (len <= 1)
		return;
	else if (len == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			swap_a(stack);
		return ;
	}
	i = 0;
	while (i < len)
	{
		if (stack->stack_a[0] < pivot)
		{
			push_b(stack);
			item_pushed++;
		}
		else
		{
			rotate_a(stack);
			item_rotate++;
		}
		i++;
	}
	if (item_rotate != stack->len_a)
	{
		temp_rotate = item_rotate;
		while (temp_rotate > 0)
		{
			reverse_rotate_a(stack);
			temp_rotate--;
		}
	}
	quick_sort_a(stack, item_rotate);
	quick_sort_b(stack, item_pushed);
}

void	quick_sort(t_stack *stack)
{
	int	*tmp_stack;

	tmp_stack = indexation(stack);
	if (!tmp_stack)
		return ;
	quick_sort_a(stack, stack->len_a);
}
