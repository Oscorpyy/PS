/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:58:12 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/05 11:38:23 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>

void	*ft_free_stash(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr_gnl(const char *s, int c, size_t *len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char *s1, char *s2, ssize_t len_s2, ssize_t len_s1);
size_t	ft_strlen_gnl(const char *s);
char	*get_next_line(int fd);

#endif
