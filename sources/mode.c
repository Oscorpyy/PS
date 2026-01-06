/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:49:29 by opernod           #+#    #+#             */
/*   Updated: 2026/01/06 12:20:24 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static int	for_bench(t_stack *stack, char	*str)
{
	if (!str)
		return (benchmode(stack, ""));
	else
		return (benchmode(stack, str));
}

int	mode(char	**str, t_stack *stack)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while ((str[i] && str[i][0] != '-') || (str[i] && str [i][1] != '-'))
		i++;
	if (ft_strcmp(str[i], "") == 0 || !str[i])
		adaptive_algo(stack);
	else if (ft_strcmp(str[i], "--simple") == 0)
		selection_sort(stack);
	else if (ft_strcmp(str[i], "--medium") == 0)
		bucket_sort_simple(stack);
	else if (ft_strcmp(str[i], "--complex") == 0)
		quick_sort(stack);
	else if (ft_strcmp(str[i], "--adaptive") == 0)
		adaptive_algo(stack);
	else if (ft_strcmp(str[i], "--bench") == 0)
		res = for_bench(stack, str[i + 1]);
	else
		return (1);
	if (res == 1)
		return (1);
	return (0);
}
