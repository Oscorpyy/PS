/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:24:26 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/16 12:03:33 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../../libft/libft.h"

int	only_num(char *str)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	if (str[0] == '-')
		i = 1;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			error = -1;
		i++;
	}
	return (error);
}

int	get_len_stack(char	**str, int len_str)
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	while (str[i] && i < len_str && only_num(str[i]) == 0)
	{
		i++;
		total++;
	}
	return (total);
}

int	*args_to_int(char **str, int strlen)
{
	int		i;
	int		*nbs;
	long	nb;
	int		error;

	i = 1;
	error = 0;
	nbs = malloc((strlen - 1) * sizeof(int));
	if (!nbs)
		return (NULL);
	while (str[i] && i < strlen && str[i][1] != '-')
	{
		error = only_num(str[i]);
		nb = ft_atol(str[i]);
		if (nb > 2147483647 || nb < -2147483648 || error == -1)
		{
			free(nbs);
			return (NULL);
		}
		nbs[i - 1] = (int)nb;
		i++;
	}
	return (nbs);
}

int	only_one(t_stack *stack)
{
	int	error;
	int	i;
	int	j;

	error = 0;
	i = 0;
	while (i < stack->len_a)
	{
		j = i + 1;
		while (j < stack->len_a)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
				error++;
			j++;
		}
		i++;
	}
	return (error);
}

void	init_all(t_stack *stack, char **argv, int argc)
{
	stack->stack_a = args_to_int(argv, argc);
	stack->len_a = get_len_stack(argv, argc);
	stack->stack_b = ft_calloc(stack->len_a, sizeof(int));
	stack->len_b = 0;
	stack->pa = 0;
	stack->pb = 0;
	stack->ra = 0;
	stack->rb = 0;
	stack->rr = 0;
	stack->rra = 0;
	stack->rrb = 0;
	stack->rrr = 0;
	stack->sa = 0;
	stack->sb = 0;
	stack->ss = 0;
	stack->total = 0;
}
