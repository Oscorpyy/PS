/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:30:40 by lgoderne          #+#    #+#             */
/*   Updated: 2025/11/14 09:47:52 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(const char *cset, char c)
{
	while (*cset != '\0')
	{
		if (c == *(cset++))
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	int		end;
	int		start;
	char	*str;

	if (!s || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] && char_in_set(set, (char)s[start]))
		start++;
	while (s[end] && char_in_set(set, (char)s[end]))
		end--;
	str = ft_substr(s, start, end - start + 1);
	return (str);
}
