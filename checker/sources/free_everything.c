
#include "../../includes/ps.h"

void	free_argv(char **new_argv, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(new_argv[i]);
		i++;
	}
	free(new_argv);
}

void	free_all(t_stack *stack, int *stack_a, int i)
{
	if (i == 1)
		ft_printf("Error\n", 2);
	if (stack)
		free(stack);
	if (stack_a)
		free(stack_a);
	return ;
}