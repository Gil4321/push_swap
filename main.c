/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:12:42 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/16 15:05:20 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(int *tab, int size)
{
	float	mistakes;
	float	pairs;
	int		i;
	int		j;

	mistakes = 0;
	pairs = 0;
	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			pairs++;
			if (tab[i] > tab[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / pairs);
}

#include <stdio.h>
void	show_stack(t_stack a)
{
	size_t	i;

	i = 0;
	while (i < a.size)
	{
		printf("%d\n", a.array[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int			*stack_a;
	int			tab_len;
	float		disorder;
	t_stack		a;
	t_stack		b;

	stack_a = error_checker(argv, argc, &tab_len);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	disorder = compute_disorder(stack_a, tab_len);
	if (disorder == 0)
	{
		free(stack_a);
		return (0);
	}
	a.array = stack_a;
	a.size = tab_len;
	b.array = malloc(sizeof(int) * tab_len);
	b.size = 0;
	medium_algo(&a, &b);
	show_stack(a);
	return (0);
}
