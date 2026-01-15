/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:12:42 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/15 16:38:43 by adghouai         ###   ########lyon.fr   */
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
	int			strategy;
	float		disorder;
	t_stack		a;
	t_stack		b;

	strategy = strategy_selector(argc, argv);
	error_checker(argv, argc, &a);
	disorder = compute_disorder(a.array, a.size);
	if (disorder == 0)
	{
		free(a.array);
		return (0);
	}
	b.array = malloc(sizeof(int) * a.size);
	b.size = 0;
	simple_algo(&a, &b);
	show_stack(a);
	return (0);
}
