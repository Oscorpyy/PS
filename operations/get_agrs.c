/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_agrs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:22:13 by opernod           #+#    #+#             */
/*   Updated: 2025/12/17 14:27:43 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int	get_size(char *args)
{
	int		fd;
	int		size_dict;
	int		reading;
	char	buffer[3];

	size_dict = 0;
	reading = 1;
	fd = open(args, O_RDONLY);
	if (fd == -1)
		write(2, " Dict Error\n", 12);
	while (reading > 0)
	{
		reading = read(fd, buffer, 1);
		size_dict ++;
	}
	close(fd);
	return (size_dict);
}

char	*dict_to_str(char *args)
{
	int		fd;
	int		size_dict;
	char	*str;

	fd = open(args, O_RDONLY);
	if (fd == -1)
		write(2, " Dict Error\n", 12);
	size_dict = get_size(args);
	str = malloc(sizeof(char) * size_dict);
	if (!str)
		return (NULL);
	read(fd, str, size_dict);
	close(fd);
	return (str);
}

t_stack	converte_arg(char	*args)
{
	char	*str;
	int		i;

	str = dict_to_str(args);
	i = 0;
	while ()
}