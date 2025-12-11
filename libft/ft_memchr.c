/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:21:41 by lgoderne          #+#    #+#             */
/*   Updated: 2025/11/14 09:44:43 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*to_char;

	to_char = (char *)s;
	i = 0;
	while (i < n)
	{
		if (to_char[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
