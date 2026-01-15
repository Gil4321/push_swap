/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:58:48 by acombier          #+#    #+#             */
/*   Updated: 2026/01/15 13:09:59 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rra
void	rra(t_stack *a)
{
	int		temp;
	size_t	i;

	if (a->size < 2)
		return ;
	temp = a->array[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = temp;
}

// rrb
void	rrb(t_stack *b)
{
	int		temp;
	size_t	i;

	if (b->size < 2)
		return ;
	temp = b->array[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = temp;
}

// rrr
void	rrr(t_stack *a, t_stack *b)
{
	int temp;
	size_t i;

	if (a->size >= 2)
	{
		temp = a->array[a->size - 1];
		i = a->size - 1;

		while (i > 0)
		{
			a->array[i] = a->array[i - 1];
			i--;
		}

		a->array[0] = temp;
	}

	if (b->size >= 2)
	{
		temp = b->array[b->size - 1];
		i = b->size - 1;

		while (i > 0)
		{
			b->array[i] = b->array[i - 1];
			i--;
		}

		b->array[0] = temp;
	}
}