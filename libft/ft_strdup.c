/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:09:23 by lgoderne          #+#    #+#             */
/*   Updated: 2025/11/14 10:05:38 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*copied_s1;

	size = ft_strlen(s1);
	copied_s1 = malloc(size * sizeof(char) + 1);
	if (!copied_s1)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		copied_s1[i] = s1[i];
		i++;
	}
	copied_s1[i] = '\0';
	return (copied_s1);
}
