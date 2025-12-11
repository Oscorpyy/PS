/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:24:14 by lgoderne          #+#    #+#             */
/*   Updated: 2025/11/20 12:29:53 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	int	i;
	int	count;
	int	sep_found;

	sep_found = 0;
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && sep_found == 0)
		{
			count++;
			sep_found = 1;
		}
		else if (s[i] == c)
			sep_found = 0;
		i++;
	}
	return (count);
}

static char	*create_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static void	*free_all(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**loop(const char *s, char **str, char c)
{
	size_t	i;
	int		current_array;
	int		word;

	current_array = 0;
	word = -1;
	i = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && s[i] && word < 0)
			word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && word >= 0)
		{
			str[current_array] = create_word(s, word, i);
			if (!(str[current_array]))
				return (free_all(str, current_array));
			word = -1;
			current_array++;
		}
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = ft_calloc((count(s, c) + 1), sizeof(char *));
	if (!str)
		return (NULL);
	return (loop(s, str, c));
}
