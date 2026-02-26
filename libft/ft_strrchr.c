/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:35:22 by lgoderne          #+#    #+#             */
/*   Updated: 2025/11/20 12:15:33 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*to_return;

	to_return = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			to_return = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
	{
		to_return = (char *)(s + i);
	}
	return (to_return);
}
