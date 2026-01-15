/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:59:45 by opernod           #+#    #+#             */
/*   Updated: 2026/01/15 18:33:29 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>

# define HEX "0123456789abcdef"
# define MAJ_HEX "0123456789ABCDEF"

typedef struct s_count
{
	size_t			count;
	int				error;
}					t_count;

int		ft_printf(const char *str, int fd, ...);
void	printp(int fd, void *point, t_count *count);
void	ft_percent(int fd, char c, va_list args, t_count *count);
void	ft_putchar(int fd, char c, t_count *count);
void	ft_putstr(int fd, char *s, t_count *count);
void	ft_putnbr(int fd, long long num, t_count *count);
void	ft_putnbr_base(int fd, size_t n, char	*base, t_count *count);
void	ft_putfloat(int fd, float num, t_count *count);

#endif
