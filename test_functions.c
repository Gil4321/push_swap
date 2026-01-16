#include <stdio.h>
#include <stddef.h>

typedef struct s_stack
{
	int	*array;
	size_t size;
}	t_stack;


int is_in_chunk(int value, int min, int chunk_num, int chunk_size)
{
	int chunk_min;
	int chunk_max;
	int is_in_range;

	chunk_min = min + (chunk_num * chunk_size);
	chunk_max = chunk_min + chunk_size - 1;

	is_in_range = (value >= chunk_min && value <= chunk_max);
	return (is_in_range);
}

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

void	find_min_max(t_stack *stack, int *min, int *max)
{
	size_t	i;

	*min = stack->array[0];
	*max = stack->array[0];

	i = 1;

	while(i < stack->size)
	{
		if(stack->array[i] < *min)
			*min = stack->array[i];
		if(stack->array[i] > *max)
			*max = stack->array[i];
			
		i++;
	}
	
}

int calculate_chunk_size(int min, int max, size_t num_chunks)
{
	return ((max - min) / num_chunks + 1);
}


size_t	find_max_index(t_stack *stack)
{
	size_t	i;
	size_t	max_index;
	int	max_value;

	if(stack->size == 0)
		return (0);
	max_index = 0;
	max_value = stack->array[0];
	i = 1;
	while(i < stack->size)
	{
		if(stack->array[i] > max_value)
		{
			max_value = stack->array[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int find_chunk_number(t_stack *a, int min, int chunk_num, int chunk_size)
{
	size_t	i;

	i = 0;

	while(i < a->size)
	{
		if(is_in_chunk(a->array[i], min, chunk_num, chunk_size))
			return ((int)i);
		i++;
	}
	return (-1);
}


int main(void)
{
	int tab[] = {10, 7, 72, 40, 52, 69, 42};

	t_stack stack;
	size_t chunks;
	int min;
	int max;
	int chunk_size;
	int max_index;
	int index;
	size_t chunk_number;

	stack.array = tab;

	stack.size = sizeof(tab) / sizeof(tab[0]);

	chunks = calculate_num_chunks(stack.size);
	find_min_max(&stack, &min, &max);
	chunk_size = calculate_chunk_size(min, max, chunks);
	max_index = find_max_index(&stack);
	chunk_number = find_chunk_number(&stack, min, chunks, chunk_size);


	printf("Number of chunk %zu\n", chunks);
	printf("Min value : %d\n", min);
	printf("Max value : %d\n", max);
	printf("Chunk size : %d\n", chunk_size);
	printf("Max index : %d\n", max_index);


		chunk_number = 0;
	while (chunk_number < chunks)
	{
		index = find_chunk_number(&stack, min, (int)chunk_number, chunk_size);
		if (index != -1)
			printf("Chunk %zu -> first matching index = %d (value=%d)\n",
				chunk_number, index, stack.array[index]);
		else
			printf("Chunk %zu -> no value found\n", chunk_number);

		chunk_number++;
	}

	return (0);
}