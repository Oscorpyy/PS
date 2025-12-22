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

static int	only_num(char *str)
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
	while (i < strlen && str[i][1] != '-')
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
