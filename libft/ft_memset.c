/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:34:01 by lgoderne          #+#    #+#             */
/*   Updated: 2025/11/14 09:45:19 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*to_char;

	to_char = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		to_char[i] = c;
		i++;
		n--;
	}
	return (to_char);
}
