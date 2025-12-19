/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:01:28 by opernod           #+#    #+#             */
/*   Updated: 2025/12/18 17:44:47 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int	*args_to_int(char **str, int strlen)
{
	int		i;
	int		*nbs;
	long	nb;

	i = 1;
	nbs = malloc((strlen - 2) * sizeof(int));
	if (!nbs)
		return (NULL);
	while (i < strlen && str[i][1] != '-')
	{
		nb = ft_atol(str[i]);
		if (nb > 2147483647 || nb < -2147483648)
		{
			free(nbs);
			return (NULL);
		}
		nbs[i - 1] = (int)nb;
		i++;
	}
	return (nbs);
}
