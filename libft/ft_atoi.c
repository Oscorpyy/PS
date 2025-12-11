/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:44:45 by lgoderne          #+#    #+#             */
/*   Updated: 2025/11/20 12:10:26 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (c);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg_mult;
	int	res;

	res = 0;
	neg_mult = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		neg_mult = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) != 0)
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	res *= neg_mult;
	return (res);
}
