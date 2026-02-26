/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:42:57 by lgoderne          #+#    #+#             */
/*   Updated: 2025/11/14 10:05:25 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	mult;
	int	res;

	mult = 1;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	while (mult <= n / 10)
		mult *= 10;
	while (mult > 0)
	{
		res = n / mult;
		n = n % mult;
		mult = mult / 10;
		res = res + '0';
		write(fd, &res, 1);
	}
}
