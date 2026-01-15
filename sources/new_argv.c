/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:56:01 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/15 17:32:43 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/includes/ft_printf.h"
#include "../includes/ps.h"

static int	total_subpart(char	**argv, int argc)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				count++;
			j++;
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
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		final_argv[to_write] = malloc(sizeof(char) * len_sub_part(argv, i));
		if (!final_argv[to_write])
			return (-1);
		j = 0;
		while (argv[i] && argv[i] != ' ')
			final_argv[to_write][j++] = argv[i++];
		final_argv[to_write][j] = '\0';
		to_write++;
		if (argv[i] == ' ')
			i++;
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
