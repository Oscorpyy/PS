#include "../ps.h"
#include "../libft/libft.h"
#include <stdio.h>

int main(void) // purpose of testing operations 
{
	int stack_a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	swap_a(stack_a);
	for (int i = 0; i < 10; i++)
	{
		printf("%i", stack_a[i]);
	}
}