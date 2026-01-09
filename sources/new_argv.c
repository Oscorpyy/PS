/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:56:01 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/09 17:07:47 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"

// static int	isdigit_loop(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str)
// 	{
// 		if (ft_isdigit(str[i]) != 1)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

static char	**ps_join(char **argv)
{
	int		i;
	int		y;
	int		to_write;
	char	**return_argv;
	int q = 0;
					int len_return = 0;
					int h = 0;


	i = 1;
	int len = 0;
	while(argv[i])
	{
		if(ft_strlen(argv[i]) > 1)
		{
					int h = 0;
					while(argv[i][h])
					{
						if(argv[i][h] != ' ' && (argv[i][h + 1] == ' ' || argv[i][h + 1] == '\0'))
							len++;
						h++;
					}
		}
		else
			len++;
		i++;
	}
	return_argv = malloc(sizeof(char *) * (len + 1));
	if (!return_argv)
		return (NULL);
	to_write = 0;
	i = 1;
	while (i <= len)
	{
			y = 0;
			len_return = 0;
			h = y;
					while(argv[i][h]!= ' ' && argv[i][h] != '\0')
					{
						len_return++;
						h++;
					}
			while (y < len_return)
			{
				while(argv[i][y] != ' ' && argv[i][y] != '\0')
				{
					
					return_argv[to_write] = malloc(sizeof(char) * len_return + 1);
					if (!return_argv[to_write])
						return (NULL);
					q = 0;
					while(q < len_return)
					{
						return_argv[to_write][q] = argv[i][y];
						q++;
						y++;
					}
					return_argv[to_write][q] = '\0';
				}
				y++;
				to_write++;
			}
		i++;
	}
	return_argv[to_write] = NULL;
	return (return_argv);
}

char	**new_argv(char **argv, int argc)
{
	char	**final_argv;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 1)
		{
			final_argv = ps_join(argv);
		}
		i++;
	}
	ft_printf("uno %s \n", 1, final_argv[0]);
	ft_printf("dos %s\n ", 1, final_argv[1]);
	ft_printf("mode %s\n ", 1, final_argv[2]);
	ft_printf("mode %s\n ", 1, final_argv[3]);
	ft_printf("mode %s\n ", 1, final_argv[4]);


	return (final_argv);
}