/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:34:24 by crmartin          #+#    #+#             */
/*   Updated: 2026/01/15 18:30:20 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static int	ft_lenstr(char **str, int size, char *sep)
{
	int	count_strs;
	int	count_sep;
	int	i;
	int	j;

	i = 0;
	count_strs = 0;
	count_sep = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			count_strs++;
			j++;
		}
		i++;
	}
	i = 0;
	while (sep[i])
	{
		count_sep++;
		i++;
	}
	return (count_strs + (count_sep * (size - 1)) + 1);
}

static char	*ft_conc(char *dest, char **strs, int size, char *sep)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			dest[k++] = strs[i][j++];
		j = 0;
		if (i == size - 1)
			return (dest);
		while (sep[j])
			dest[k++] = sep[j++];
		i++;
	}
	dest[k] = '\0';
	return (dest);
}

char	*strjoin_all(int size, char **strs, char *sep)
{
	char	*empty;
	char	*dest;
	int		total_size;
	char	*sep_null;

	sep_null = "";
	dest = 0;
	total_size = 0;
	if (size == 0)
	{
		empty = malloc(1);
		empty[0] = '\0';
		return (empty);
	}
	if (!sep)
		sep = sep_null;
	total_size = ft_lenstr(strs, size, sep);
	dest = malloc((total_size) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_conc(dest, strs, size, sep);
	return (dest);
}
