/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoderne <lgoderne@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:36:52 by lgoderne          #+#    #+#             */
/*   Updated: 2025/12/16 11:46:04 by lgoderne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	swap_a(int *stack_a)
{
	int temp;

	// if ( <= 1)
	// 	return (0);
	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
}