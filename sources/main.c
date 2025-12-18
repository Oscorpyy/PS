/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:35:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/18 13:09:13 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static void init_all(t_stack *stack)
{
	stack->pa = 0;
	stack->pb = 0;
	stack->ra = 0;
	stack->rb = 0;
	stack->rr = 0;
	stack->rra = 0;
	stack->rrb = 0;
	stack->rrr = 0;
	stack->sa = 0;
	stack->sb = 0;
	stack->ss = 0;
	stack->total = 0;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (0);
}
