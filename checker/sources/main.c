/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 20:20:38 by azazel            #+#    #+#             */
/*   Updated: 2025/12/23 20:11:38 by azazel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/ps.h"
#include "../includes/checker.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (is_args_good(argv) == ERROR)
	{
		ft_printf("Error");
		return (-1);
	}
	return (0);
}
