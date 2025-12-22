/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:54:10 by opernod           #+#    #+#             */
/*   Updated: 2025/11/18 11:18:48 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c, t_count *count)
{
	int	temp;

	temp = write(1, &c, 1);
	if (temp < 0)
		count->error = -1;
	count->count++;
}

void	ft_putstr(char *s, t_count *count)
{
	int	temp;
	int	len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	temp = write(1, s, len);
	if (temp < 0)
		count->error = -1;
	count->count += len;
}

void	ft_putnbr(long long num, t_count *count)
{
	char		temp;

	if (num < 0)
	{
		ft_putchar('-', count);
		num = -num;
	}
	if (num > 9)
		ft_putnbr(num / 10, count);
	temp = ((num % 10) + '0');
	ft_putchar(temp, count);
}

void	ft_putnbr_base(size_t n, char	*base, t_count *count)
{
	char	temp;
	int		check;

	if (n >= 16)
		ft_putnbr_base(n / 16, base, count);
	temp = base[(n % 16)];
	check = write (1, &temp, 1);
	if (check < 0)
		count->error = -1;
	count->count ++;
}

void	ft_putfloat(float num, t_count *count)
{
	int	int_part;
	int	dec_part;

	if (num < 0)
	{
		ft_putchar('-', count);
		num = -num;
	}
	int_part = (int)num;
	dec_part = (int)((num - int_part) * 100 + 0.5f);
	ft_putnbr(int_part, count);
	ft_putchar('.', count);
	if (dec_part < 10)
		ft_putchar('0', count);
	ft_putnbr(dec_part, count);
}
