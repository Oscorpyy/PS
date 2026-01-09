/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:01:28 by opernod           #+#    #+#             */
/*   Updated: 2026/01/09 15:07:50 by lgoderne         ###   ########lyon.fr   */
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

int	get_len_stack(char	**str, int len_str)
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	while (i < len_str && only_num(str[i]) == 0)
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

	i = 0;
	error = 0;
	nbs = malloc((strlen) * sizeof(int));
	if (!nbs)
		return (NULL);
	while (i < strlen && str[i][1] != '-')
	{
		error = only_num(str[i]);
		nb = ft_atol(str[i]);
		if (nb > INT_MAX || nb < INT_MIN || error == -1)
		{
			free(nbs);
			return (NULL);
		}
		nbs[i] = (int)nb;
		i++;
	}
	return (nbs);
}
