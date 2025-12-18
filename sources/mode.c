/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:49:29 by opernod           #+#    #+#             */
/*   Updated: 2025/12/18 14:44:26 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	mode(char	**str, t_stack *stack)
{
	int		i;
	int		j;
	char	mode;

	i = 0;
	j = 0;
	while(str[i][0] != '-' && str [i][1] != '-')
		i++;
	if (ft_strncmp(str[i], "--simple", 8))
		stack->total += selection_sort(stack);
	else if (ft_strncmp(str[i], "--medium ", 8))
		stack->total +=	bucket_sort(stack);	
	else if (ft_strncmp(str[i], "--complex", 9))
		stack->total += radix(stack);
	else if (ft_strncmp(str[i], "--bench", 7))
		stack->total += benchmode(stack);
	else
		stack->total += adaptive_algo(stack);

}
