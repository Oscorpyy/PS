/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:59:45 by opernod           #+#    #+#             */
/*   Updated: 2025/11/18 11:18:47 by opernod          ###   ########lyon.fr   */
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

int		ft_printf(const char *str, ...) __attribute__((format(printf, 1, 2)));
void	printp(void *point, t_count *count);
void	ft_percent(char c, va_list args, t_count *count);
void	ft_putchar(char c, t_count *count);
void	ft_putstr(char *s, t_count *count);
void	ft_putnbr(long long num, t_count *count);
void	ft_putnbr_base(size_t n, char	*base, t_count *count);
size_t	ft_strlen(const char *str);

#endif
