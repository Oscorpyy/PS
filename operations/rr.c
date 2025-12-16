/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:19:43 by opernod           #+#    #+#             */
/*   Updated: 2025/12/16 13:13:02 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	rotate_r(int *stack_a, int *stack_b, int len_a, int len_b)
{
	rotate_a(stack_a, len_a);
	rotate_b(stack_b, len_b);
}
