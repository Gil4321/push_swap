/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_selector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:34:56 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/15 18:16:16 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char	*s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

static void	parse_strategy(char *arg, int *strat, int *strat_nb)
{
	if (ft_strcmp(arg, "--simple") == 0)
	{
		(*strat) = 1;
		(*strat_nb)++;
	}
	else if (ft_strcmp(arg, "--medium") == 0)
	{
		(*strat) = 2;
		(*strat_nb)++;
	}
	else if (ft_strcmp(arg, "--complex") == 0)
	{
		(*strat) = 3;
		(*strat_nb)++;
	}
	else if (ft_strcmp(arg, "--adaptive") == 0)
		(*strat_nb)++;
	if ((*strat_nb) > 1)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

int	strategy_selector(int argc, char **argv)
{
	int		strat_nb;
	int		strat;
	int		i;

	i = 1;
	strat = 4;
	strat_nb = 0;
	while (i < argc)
	{
		parse_strategy(argv[i], &strat, &strat_nb);
		i++;
	}
	return (strat);
}
