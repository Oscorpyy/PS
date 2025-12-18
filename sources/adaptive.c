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
		// selection_sort(stack);
		return ("--simple");
	}
	else if(0.2 <= numdis && numdis < 0.5)
	{
		// bucket_sort_simple(stack);
		return ("--medium");
	}
	else
	{
		// radix(stack);
		return ("--complex");
	}
}

static void	print_bench(t_stack *stack, float numdis, char *mode, int ada)
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
	printf("[bench] disorder: %f%%\n", numdis);
	printf("[bench] strategy: %s / %s\n", mode, complexity);
	printf("[bench] total_ops: %i\n", stack->total);
	printf("[bench] sa: %i, sb: %i, ss: %i,",stack->sa, stack->sb, stack->ss);
	printf(" pa: %i, pb: %i\n", stack->pa, stack->pb);
	printf("[bench] ra: %i, rb: %i, rr: %i", stack->ra, stack->rb, stack->rr);
	printf(", rra: %i, rrb: %i, rrr: %i\n", stack->rra, stack->rrb, stack->rrr);
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
			printf("selection_sort(stack);");
		else if (ft_strcmp(mode, "--medium ") == 0)
			printf("bucket_sort(stack);");
		else if (ft_strcmp(mode, "--complex") == 0)
			printf("radix(stack);");
		else 
			printf("adap_algo_mode = adaptive_algo(stack);");
	}
	if (ft_strcmp(mode, "") == 0)
		print_bench(stack, numdis, adap_algo_mode, 1);
	else
		print_bench(stack, numdis, mode, 0);
}

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
	int 	*stack_a;
	int		stack_b[500];
	int		i;
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack_a = args_to_int(argv, argc);
	stack->stack_a = stack_a;
	stack->stack_b = stack_b;
	stack->len_a = 5;
	stack->len_b = 0;
	init_all(stack);
	i = 0;
	mode(argv, stack);
	if (!stack->stack_a)
	{
		printf("abuse frr on as dit un int");
		return(0);
	}
	while (i != argc - 1)
	{
		printf("stack[%i] = %i \n", i, stack->stack_a[i]);
		i++;
	}
	printf("disorder = %f\n", disorder(stack));
	free(stack);
	free(stack_a);
}