/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:01:28 by opernod           #+#    #+#             */
/*   Updated: 2025/12/18 12:50:11 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int	*args_to_int(char **str, int strlen)
{
	int		i;
	int		*nbs;
	long	nb;
	
	i = 1;
	nbs = malloc((strlen - 2) * sizeof(int));
	while(i < strlen && str[i][1] != '-')
	{
		nb = ft_atoi(str[i]);
		if (nb > 2147483647 || nb < -2147483648)
		{
			free(nbs);
			return (NULL);
		}
		nbs[i - 1] = (int)nb;
		i++;
	}
	return (nbs);
}

int	main(int argc, char **argv)
{
	int	*nb;
	int	i;

	if (argc < 3)
	{
		if (argc == 2)
			printf("%s", argv[1]);
		return (0);
	}
	nb = args_to_int(argv, argc);
	i = 0;
	if (!nb)
	{
		printf("abuse frr on as dit un int");
		return(0);
	}
	while (i != argc - 1)
	{
		printf("stack[%i] = %i \n", i, nb[i]);
		i++;
	}
}