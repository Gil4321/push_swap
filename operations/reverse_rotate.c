/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:58:48 by acombier          #+#    #+#             */
/*   Updated: 2026/01/13 11:05:17 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra
void	rra(t_stack *a)
{
	int	temp;
	int	i;

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
	printf("rra\n");
}
// rrb
void	rrb(t_stack *b)
{
	int	temp;
	int	i;

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
	printf("rrb\n");
}

// rrr
void	rrr(t_stack *a, t_stack *b)
{
	int		temp;
	int		i;

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

	printf("rrr\n");
}