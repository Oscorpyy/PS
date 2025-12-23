/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:22:02 by azazel            #+#    #+#             */
/*   Updated: 2025/12/23 20:10:39 by azazel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ps.h"
#include "../includes/checker.h"
#include "../../libft/libft.h"

int is_args_good(char	**argv)
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
