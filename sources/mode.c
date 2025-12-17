/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:49:29 by opernod           #+#    #+#             */
/*   Updated: 2025/12/17 19:03:42 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int	mode(char	**str, t_stack *stack)
{
	int		i;
	int		j;
	char	mode;
	int		total;

	i = 0;
	j = 0;
	while(str[i][0] != '-' && str [i][1] != '-')
		i++;
	if (ft_strncmp(str[i], "--simple", 8))
		total = selection_sort(stack);
	else if (ft_strncmp(str[i], "--medium ", 8))
		total =	bucket_sort(stack);	
	else if (ft_strncmp(str[i], "--complex", 9))
		total = radix(stack);
	else if (ft_strncmp(str[i], "--bench", 7))
		total = benchmode(stack);
	else
		total = adaptive_algo(stack);
	return (total);
}
