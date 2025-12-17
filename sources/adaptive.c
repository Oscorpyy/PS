/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:46:46 by opernod           #+#    #+#             */
/*   Updated: 2025/12/17 16:19:33 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	adaptive_algo(t_stack *stack)
{
	float	numdis;
	int		total;

	numdis = disorder(stack);
	if (numdis < 0.2)
		total = selection_sort(stack);
	else if(0.2 <= numdis && numdis < 0.5)
		total++; //total = fonction de golemong
	else
		total = radix(stack);
}