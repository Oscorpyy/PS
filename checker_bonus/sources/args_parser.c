/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:22:02 by lgoderne          #+#    #+#             */
/*   Updated: 2026/02/27 11:00:52 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../../libft/libft.h"

int	is_args_good(char	**argv)
{
	int	i;
	int	y;

	i = 1;
	while (argv[i])
	{
		y = 0;
		if (argv[i][0] == '-' && argv[i][1] != '\0')
			y = 1;
		while (argv[i][y])
		{
			if (ft_isdigit(argv[i][y]) == 0)
				return (ERROR);
			y++;
		}
		i++;
	}
	return (0);
}
