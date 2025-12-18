/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_agrs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:40:30 by opernod           #+#    #+#             */
/*   Updated: 2025/12/18 13:06:17 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*read_file_to_array(const char *filename, int *size)
{
	FILE	*file;
	int		*array;
	int		value;
	int		count = 0;
	int		i = 0;

	file = fopen(filename, "r");
	if (!file)
		return NULL;
	while (fscanf(file, "%d", &value) == 1)
		count++;
	if (count == 0)
	{
		fclose(file);
		return NULL;
	}
	array = malloc(sizeof(int) * count);
	if (!array)
	{
		fclose(file);
		return NULL;
	}
	rewind(file);
	while (fscanf(file, "%d", &value) == 1)
		array[i++] = value;
	fclose(file);
		size = count;
	return array;
}
