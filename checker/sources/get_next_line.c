/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 23:59:06 by azazel            #+#    #+#             */
/*   Updated: 2025/12/27 18:53:22 by azazel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../../libft/libft.h"

static char	*read_to_stash(int fd, char *stash)
{
	char		*read_str;
	int			read_return;
	size_t		i;

	read_return = 1;
	read_str = malloc(BUFFER_SIZE + 1);
	if (!read_str)
		return (ft_free_stash(stash, NULL));
	while (!ft_strchr_gnl(stash, '\n', &i) && read_return > 0)
	{
		read_return = read(fd, read_str, BUFFER_SIZE);
		if (read_return == -1)
			return (ft_free_stash(read_str, stash));
		if (read_return == 0 && (!stash || *stash == '\0'))
			return (ft_free_stash(stash, read_str));
		read_str[read_return] = '\0';
		stash = ft_strjoin_gnl(stash, read_str, read_return, i);
		if (!stash)
			return (ft_free_stash(read_str, NULL));
	}
	ft_free_stash(read_str, NULL);
	return (stash);
}

static char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + (stash[i] == '\n') + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(stash) - i + 1));
	if (!str)
	{
		free(stash);
		return (NULL);
	}
	i++;
	j = 0;
	while (stash[i])
		str[j++] = stash[i++];
	str[j] = '\0';
	free(stash);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		stash = NULL;
		return (0);
	}
	if (!stash)
		stash = ft_strdup("");
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clean_stash(stash);
	return (line);
}
