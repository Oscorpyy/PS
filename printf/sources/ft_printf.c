/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:58:08 by opernod           #+#    #+#             */
/*   Updated: 2026/01/08 17:33:49 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	printp(int fd, void *point, t_count *count)
{
	if (point == NULL)
		ft_putstr(fd, "(nil)", count);
	else
	{
		ft_putstr(fd, "0x", count);
		ft_putnbr_base(fd, (size_t)point, HEX, count);
	}
}

void	ft_percent(int fd, char c, va_list args, t_count *count)
{
	if (c == 'c')
		ft_putchar(fd, va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(fd, va_arg(args, char *), count);
	else if (c == 'p')
		printp(fd, va_arg(args, void *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(fd, (long long)va_arg(args, int), count);
	else if (c == 'u')
		ft_putnbr(fd, (long long)va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_putnbr_base(fd, (size_t)va_arg(args, unsigned int), HEX, count);
	else if (c == 'X')
		ft_putnbr_base(fd, (size_t)va_arg(args, unsigned int), MAJ_HEX, count);
	else if (c == '%')
		ft_putchar(fd, '%', count);
	else if (c == 'f')
		ft_putfloat(fd, va_arg(args, double), count);
}

int	ft_printf(const char *to_print, int fd, ...)
{
	char	*str;
	t_count	count;
	va_list	args;

	va_start(args, fd);
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
			ft_percent(fd, *str++, args, &count);
		}
		else if (*str != '\0')
			ft_putchar(fd, *str++, &count);
	}
	va_end(args);
	if (count.error == -1)
		return (count.error);
	return (count.count);
}
