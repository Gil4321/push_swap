/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:58:29 by acombier          #+#    #+#             */
/*   Updated: 2026/01/15 13:09:40 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ra
void	ra(t_stack *a)
{
	int		temp;
	size_t	i;

	if (a->size < 2)
		return ;
	temp = a->array[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[a->size - 1] = temp;
}
// rb
void	rb(t_stack *b)
{
	int		temp;
	size_t	i;

	if (b->size < 2)
		return ;
	temp = b->array[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->array[b->size - 1] = temp;
}

// rr
void	rr(t_stack *a, t_stack *b)
{
	int		temp;
	size_t	i;

	if (a->size >= 2)
	{
		temp = a->array[0];
		i = 0;
		while (i < a->size - 1)
		{
			a->array[i] = a->array[i + 1];
			i++;
		}
		a->array[a->size - 1] = temp;
	}
	if (b->size >= 2)
	{
		temp = b->array[0];
		i = 0;
		while (i < b->size - 1)
		{
			b->array[i] = b->array[i + 1];
			i++;
		}
		b->array[b->size - 1] = temp;
	}
}
