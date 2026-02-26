/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:31:42 by lgoderne          #+#    #+#             */
/*   Updated: 2025/11/20 12:26:37 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_str;
	unsigned char	*src_str;
	size_t			i;

	if ((!dest && !src) || !n)
		return (dest);
	dest_str = (unsigned char *)dest;
	src_str = (unsigned char *)src;
	i = 0;
	while (n > 0)
	{
		dest_str[i] = src_str[i];
		i++;
		n--;
	}
	return (dest_str);
}
