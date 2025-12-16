/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:51:07 by lgoderne          #+#    #+#             */
/*   Updated: 2025/12/16 12:57:15 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

float	disorder(int *stack_a)
{
	float	mistakes;
	float	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < ft_stacksize(stack_a) - 1)
	{
		j = i + 1;
		while (j < ft_stacksize(stack_a) - 1)
		{
			total_pairs += 1;
			if (stack_a[i] > stack_a[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);	
}
