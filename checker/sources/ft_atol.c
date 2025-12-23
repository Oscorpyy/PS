/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:44:45 by lgoderne          #+#    #+#             */
/*   Updated: 2025/12/23 22:46:56 by azazel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (c);
	return (0);
}

static int	ft_isdigit(int character)
{
	if ((character >= 48 && character <= 57))
		return (1);
	else
		return (0);
}

long	ft_atol(const char *str)
{
	int		i;
	int		neg_mult;
	long	res;

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
