/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:46:37 by lgoderne          #+#    #+#             */
/*   Updated: 2025/12/16 13:56:36 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

#include <stdio.h>

void	swap_a(int *stack_a, int len_a);
void	swap_b(int *stack_b, int len_b);
void	swap_s(int *stack_a, int *stack_b, int len_a, int len_b);
void	push_a(int *stack_a, int *stack_b, int len_a, int len_b);
void	push_b(int *stack_a, int *stack_b, int len_a, int len_b);
void	rotate_a(int *stack_a, int len_a);
void	rotate_b(int *stack_b, int len_b);
void	rotate_r(int *stack_a, int *stack_b, int len_a, int len_b);
void	reverse_rotate_a(int *stack_a, int len_a);
void	reverse_rotate_b(int *stack_b, int len_b);
void	reverse_rotate_r(int *stack_a, int *stack_b, int len_a, int len_b);

#endif
