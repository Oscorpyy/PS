/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:23:09 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/16 12:06:13 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	argc_updated(char **new_argv)
{
	int	i;

	i = 0;
	while (new_argv[i])
		i++;
	return (i);
}
