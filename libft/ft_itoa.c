/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:53:10 by lgoderne          #+#    #+#             */
/*   Updated: 2025/11/14 10:04:48 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_length(long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	is_n_negative(long *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char		*str;
	long		nlong;
	long int	i;
	long int	multp;

	nlong = n;
	str = malloc(count_length(nlong) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (is_n_negative(&nlong) == 1)
		str[i++] = '-';
	multp = 1;
	while (multp <= nlong / 10)
		multp *= 10;
	while (multp > 0)
	{
		str[i++] = (nlong / multp) + '0';
		nlong = nlong % multp;
		multp /= 10;
	}
	str[i] = '\0';
	return (str);
}
