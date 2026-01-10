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

#include "../printf/includes/ft_printf.h"
#include "../includes/ps.h"

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
			return (len);
		index++;
		len++;
	}
	return (len);
}

// static void	sub_part_creation(char	*sub_argv, int	*to_write, char	**final_argv)
// {
	
// }

char	**new_argv(char **argv, int *argc)
{
	int		len_subpart;
	char	**final_argv;
	int		i;
	int		y;
	int		k;
	int		to_write;

	len_subpart = total_subpart(argv, *argc);
	final_argv = malloc(sizeof(char	*) * (len_subpart + 1));
	if (!final_argv)
		return (NULL);
	to_write = 0;
	i = 0;
	while (i < *argc)
	{
		y = 0;
		k = 0;
		final_argv[to_write] = malloc(sizeof(char) * (len_sub_part(argv[i], y) + 1));
		if (!final_argv[to_write])
			return (NULL);
		while (argv[i][y])
		{
			if (argv[i][y] == ' ')
			{
				final_argv[to_write][k] = '\0';
				to_write += 1;
				y++;
				k = 0;
				final_argv[to_write] = malloc(sizeof(char) * (len_sub_part(argv[i], y) + 1));
				if (!final_argv)
					return (NULL);
				continue;
			}
			final_argv[to_write][k] = argv[i][y];
			k++;
			y++;
		}
		final_argv[to_write][k] = '\0';
		to_write += 1;
		i++;
	}
	final_argv[to_write] = NULL;
	*argc = len_subpart;
	return (final_argv);
}
