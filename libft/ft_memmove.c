/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:17:45 by lgoderne          #+#    #+#             */
/*   Updated: 2025/11/20 12:25:25 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_str;
	char	*src_str;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	dest_str = (char *)dest;
	src_str = (char *)src;
	if (dest_str < src_str)
	{
		i = 0;
		while (i < n)
		{
			dest_str[i] = src_str[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			dest_str[n] = src_str[n];
	}
	return (dest_str);
}
