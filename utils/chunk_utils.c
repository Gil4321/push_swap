/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:51:51 by acombier          #+#    #+#             */
/*   Updated: 2026/01/15 18:24:37 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

