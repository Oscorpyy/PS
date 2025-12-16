/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:22:06 by opernod           #+#    #+#             */
/*   Updated: 2025/12/16 13:53:25 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	reverse_rotate_r(int *stack_a, int *stack_b, int len_a, int len_b)
{
	reverse_rotate_a(stack_a, len_a);
	reverse_rotate_b(stack_b, len_b);
}
