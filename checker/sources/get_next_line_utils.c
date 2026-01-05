/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:58:02 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/05 11:38:26 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	*ft_free_stash(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	size;
	char	*copied_s1;

	size = ft_strlen_gnl(s1);
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

char	*ft_strchr_gnl(const char *s, int c, size_t *len)
{
	size_t		i;

	*len = 0;
	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			*len = i;
			return ((char *)(s + i));
		}
		i++;
	}
	*len = i;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2, ssize_t len_s2, ssize_t len_s1)
{
	char	*str;
	ssize_t	i;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(len_s1 + len_s2 * sizeof(char) + 1);
	if (!str)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	i = -1;
	if (s1)
		while (++i < len_s1)
			str[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		str[i + len_s1] = s2[i];
	str[i + len_s1] = '\0';
	if (s1)
		free(s1);
	return (str);
}
