/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:12:42 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/12 16:23:02 by adghouai         ###   ########lyon.fr   */
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

/* #include <stdio.h>
fonction de test pour afficher un tableau
void	show_stack(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
} */

int	main(int argc, char **argv)
{
	int			*stack_a;
	int			tab_len;
	float		disorder;

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
//	show_stack(stack_a, tab_len);
	return (0);
}
