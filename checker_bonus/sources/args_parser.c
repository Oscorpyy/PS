/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:22:02 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/06 12:27:48 by lgoderne         ###   ########lyon.fr   */
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
		while (argv[i][y])
		{
			if (argv[i][0] == '-')
				y = 1;
			if (ft_isdigit(argv[i][y]) == 0)
				return (ERROR);
			y++;
		}
		i++;
	}
	return (0);
}
