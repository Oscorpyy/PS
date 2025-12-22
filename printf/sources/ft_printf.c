/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:58:08 by opernod           #+#    #+#             */
/*   Updated: 2025/11/18 11:32:54 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printp(void *point, t_count *count)
{
	if (point == NULL)
		ft_putstr("(nil)", count);
	else
	{
		ft_putstr("0x", count);
		ft_putnbr_base((size_t)point, HEX, count);
	}
}

size_t	ft_strlen(const char *str)
{
	int	total;

	total = 0;
	while (*str != '\0')
	{
		str++;
		total++;
	}
	return (total);
}

void	ft_percent(char c, va_list args, t_count *count)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'p')
		printp(va_arg(args, void *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr((long long)va_arg(args, int), count);
	else if (c == 'u')
		ft_putnbr((long long)va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_putnbr_base((size_t)va_arg(args, unsigned int), HEX, count);
	else if (c == 'X')
		ft_putnbr_base((size_t)va_arg(args, unsigned int), MAJ_HEX, count);
	else if (c == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *to_print, ...)
{
	char	*str;
	t_count	count;
	va_list	args;

	va_start(args, to_print);
	count.count = 0;
	count.error = 0;
	if (!to_print)
		count.error = -1;
	str = (char *)to_print;
	while (str && *str != '\0')
	{
		if (*str == '%')
		{
			str++;
			ft_percent(*str++, args, &count);
		}
		else if (*str != '\0')
			ft_putchar(*str++, &count);
	}
	va_end(args);
	if (count.error == -1)
		return (count.error);
	return (count.count);
}
