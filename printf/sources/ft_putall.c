/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:54:10 by opernod           #+#    #+#             */
/*   Updated: 2026/01/05 14:56:33 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(int fd, char c, t_count *count)
{
	int	temp;

	temp = write(fd, &c, 1);
	if (temp < 0)
		count->error = -1;
	count->count++;
}

void	ft_putstr(int fd, char *s, t_count *count)
{
	int	temp;
	int	len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	temp = write(fd, s, len);
	if (temp < 0)
		count->error = -1;
	count->count += len;
}

void	ft_putnbr(int fd, long long num, t_count *count)
{
	char		temp;

	if (num < 0)
	{
		ft_putchar(fd, '-', count);
		num = -num;
	}
	if (num > 9)
		ft_putnbr(fd, num / 10, count);
	temp = ((num % 10) + '0');
	ft_putchar(fd, temp, count);
}

void	ft_putnbr_base(int fd, size_t n, char	*base, t_count *count)
{
	char	temp;
	int		check;

	if (n >= 16)
		ft_putnbr_base(fd, n / 16, base, count);
	temp = base[(n % 16)];
	check = write (fd, &temp, 1);
	if (check < 0)
		count->error = -1;
	count->count ++;
}

void	ft_putfloat(int fd, float num, t_count *count)
{
	int	int_part;
	int	dec_part;

	if (num < 0)
	{
		ft_putchar(fd, '-', count);
		num = -num;
	}
	int_part = (int)num;
	dec_part = (int)((num - int_part) * 100 + 0.5f);
	ft_putnbr(fd, int_part, count);
	ft_putchar(fd, '.', count);
	if (dec_part < 10)
		ft_putchar(fd, '0', count);
	ft_putnbr(fd, dec_part, count);
}
