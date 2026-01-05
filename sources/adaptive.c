/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:46:46 by opernod           #+#    #+#             */
/*   Updated: 2026/01/05 15:24:38 by opernod          ###   ########lyon.fr   */
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

static void	printf_bench(t_stack *stack, float numdis, char *mode, char *On)
{
	ft_printf("[bench] disorder: %f%%\n", 2, (numdis * 100));
	ft_printf("[bench] strategy: %s / %s\n", 2, mode, On);
	ft_printf("[bench] total_ops: %i\n", 2, stack->total);
	ft_printf("[bench] sa: %i, sb: %i, ", 2, stack->sa, stack->sb);
	ft_printf("ss: %i, pa: %i, pb: %i\n", 2, stack->ss, stack->pa, stack->pb);
	ft_printf("[bench] ra: %i, rb: %i, ", 2, stack->ra, stack->rb);
	ft_printf("rr: %i, rra: %i, rrb: %i", 2, stack->rr, stack->rra, stack->rrb);
	ft_printf(", rrr: %i\n", 2, stack->rr);
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
		mode = "Adaptive";
	printf_bench(stack, numdis, mode, complexity);
}

int	benchmode(t_stack *stack, char *mode)
{
	float	numdis;
	char	*adap_algo_mode;

	adap_algo_mode = "";
	numdis = disorder(stack);
	if (ft_strcmp(mode, "") == 0 || !mode)
		adap_algo_mode = adaptive_algo(stack);
	else if (ft_strcmp(mode, "--simple") == 0)
		selection_sort(stack);
	else if (ft_strcmp(mode, "--medium") == 0)
		bucket_sort_simple(stack);
	else if (ft_strcmp(mode, "--complex") == 0)
		radix_sort(stack);
	else if (ft_strcmp(mode, "--adaptive") == 0)
	{
		mode = "";
		adap_algo_mode = adaptive_algo(stack);
	}
	else
		return (1);
	if (ft_strcmp(mode, "") == 0 || !mode)
		infos_bench(stack, numdis, adap_algo_mode, 1);
	else
		infos_bench(stack, numdis, mode, 0);
	return (0);
}
