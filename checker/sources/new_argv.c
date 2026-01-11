/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:56:01 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/09 17:07:47 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"

static int	total_subpart(char	**argv, int argc)
{
	int	i;
	int	y;
	int	count;

	count = 0;
	i = 0;
	while (i < argc)
	{
		y = 0;
		while (argv[i][y])
		{
			if (argv[i][y] == ' ')
				count++;
			y++;
		}
		count++;
		i++;
	}
	return (count);
}

static int	len_sub_part(char *sub_argv, int index)
{
	int	len;

	len = 0;
	while (sub_argv[index])
	{
		if (sub_argv[index] == ' ')
			return (len + 1);
		index++;
		len++;
	}
	return (len + 1);
}

static int	sub_part_creation(char *argv, int to_write, char **final_argv)
{
	int	y;
	int	k;

	y = 0;
	while (argv[y])
	{
		final_argv[to_write] = malloc(sizeof(char) * len_sub_part(argv, y));
		if (!final_argv[to_write])
			return (-1);
		k = 0;
		while (argv[y] && argv[y] != ' ')
			final_argv[to_write][k++] = argv[y++];
		final_argv[to_write][k] = '\0';
		to_write++;
		if (argv[y] == ' ')
			y++;
	}
	return (to_write);
}

char	**new_argv(char **argv, int *argc)
{
	int		len_subpart;
	char	**final_argv;
	int		i;
	int		to_write;

	len_subpart = total_subpart(argv, *argc);
	final_argv = malloc(sizeof(char *) * (len_subpart + 1));
	if (!final_argv)
		return (NULL);
	to_write = 0;
	i = 0;
	while (i < *argc)
	{
		to_write = sub_part_creation(argv[i], to_write, final_argv);
		if (to_write == -1)
		{
			free_argv(final_argv, to_write);
			return (NULL);
		}
		i++;
	}
	final_argv[to_write] = NULL;
	*argc = len_subpart;
	return (final_argv);
}
