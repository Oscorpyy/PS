/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:49:29 by opernod           #+#    #+#             */
/*   Updated: 2025/12/21 12:36:26 by azazel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	mode(char	**str, t_stack *stack)
{
	int		i;
	// int		j;

	i = 0;
	// j = 0;
	while ((str[i] && str[i][0] != '-') || (str[i] && str [i][1] != '-'))
		i++;
	if (ft_strcmp(str[i], "--simple") == 0)
		printf("selection_sort(stack);");
	else if (ft_strcmp(str[i], "--medium") == 0)
		bucket_sort_simple(stack);
	else if (ft_strcmp(str[i], "--complex") == 0)
		radix(stack);
	else if (ft_strcmp(str[i], "--bench") == 0)
	{
		if (!str[i + 1])
			benchmode(stack, "");
		else
			benchmode(stack, str[i + 1]);
	}
	// else
	// 	printf("adap_algo_mode = adaptive_algo(stack);");
	//adaptive_algo(stack);
}
