/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:46:46 by opernod           #+#    #+#             */
/*   Updated: 2025/12/18 19:36:28 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

char	*adaptive_algo(t_stack *stack)
{
	float	numdis;

	numdis = disorder(stack);
	if (numdis < 0.2)
	{
		selection_sort(stack);
		return ("--simple");
	}
	else if (0.2 <= numdis && numdis < 0.5)
	{
		bucket_sort_simple(stack);
		return ("--medium");
	}
	else
	{
		radix_sort(stack);
		return ("--complex");
	}
}

static void	putstr_bench()
{
	printf("[bench] disorder: %f%%\n", numdis);
	printf("[bench] strategy: %s / %s\n", mode, complexity);
	printf("[bench] total_ops: %i\n", stack->total);
	printf("[bench] sa: %i, sb: %i, ss: %i,", stack->sa, stack->sb, stack->ss);
	printf(" pa: %i, pb: %i\n", stack->pa, stack->pb);
	printf("[bench] ra: %i, rb: %i, rr: %i", stack->ra, stack->rb, stack->rr);
	printf(", rra: %i, rrb: %i, rrr: %i\n", stack->rra, stack->rrb, stack->rrr);
}

static void	infos_bench(t_stack *stack, float numdis, char *mode, int ada)
{
	char	*complexity;

	complexity = "";
	if (ft_strcmp(mode, "--simple") == 0)
	{
		complexity = "O(n2)";
		mode = "Simple";
	}
	else if (ft_strcmp(mode, "--medium") == 0)
	{
		complexity = "O(n√n)";
		mode = "Medium";
	}
	else if (ft_strcmp(mode, "--complex") == 0)
	{
		complexity = "O(n log n)";
		mode = "Complex";
	}
	if (ada == 1)
		mode = "Adaptative";

}

void	benchmode(t_stack *stack, char *mode)
{
	float	numdis;
	char	*adap_algo_mode;

	adap_algo_mode = "";
	numdis = disorder(stack);
	if (ft_strcmp(mode, "") == 0)
		adap_algo_mode = adaptive_algo(stack);
	else
	{
		if (ft_strcmp(mode, "--simple") == 0)
			selection_sort(stack);
		else if (ft_strcmp(mode, "--medium") == 0)
			bucket_sort_simple(stack);
		else if (ft_strcmp(mode, "--complex") == 0)
			radix_sort(stack);
		else
		{
			mode = "";
			adap_algo_mode = adaptive_algo(stack);
		}
	}
	if (ft_strcmp(mode, "") == 0)
		infos_bench(stack, numdis, adap_algo_mode, 1);
	else
		infos_bench(stack, numdis, mode, 0);
}
