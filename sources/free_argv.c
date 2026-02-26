/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:35:18 by opernod           #+#    #+#             */
/*   Updated: 2026/01/16 10:58:06 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	free_argv(char **new_argv, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(new_argv[i]);
		i++;
	}
	free(new_argv);
}
