#include <stdio.h>
#include <stddef.h>

typedef struct s_stack
{
	int	*array;
	size_t size;
}	t_stack;

size_t	ft_sqrt(int nb)
{
	size_t	i;
	i = 1;
	while(i * i <= nb)
	{
		if(i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

size_t	calculate_num_chunks(size_t size)
{
	size_t num_chunks;
	
	num_chunks = ft_sqrt(size);
	
	if(num_chunks < 2)
		num_chunks = 2;
		
	return (num_chunks);
}

int main(void)
{
	int tab[] = {10, 7, 72, 40, 52, 69, 42};

	t_stack stack;
	size_t chunks;

	stack.array = tab;

	stack.size = sizeof(tab) / sizeof(tab[0]);

	chunks = calculate_num_chunks(stack.size);

	printf("Number of chunk %zu", chunks);
	
	return (0);
}