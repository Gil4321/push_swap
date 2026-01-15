/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:01:02 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/14 17:36:07 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	digit_check(char **tab, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (tab[i][j])
		{
			if (!(ft_isdigit(tab[i][j])) && tab[i][j] != ' '
				&& tab[i][j] != '-')
				return (0);
			if (tab[i][j] == '-')
			{
				if (ft_isdigit(tab[i][j + 1]) == 0
					|| (j != 0 && tab[i][j - 1] != ' '))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	range_check(char **tab)
{
	int			i;
	long int	arg;

	i = 0;
	while (tab[i])
	{
		arg = ft_atoi(tab[i]);
		if ((arg > INT_MAX) || (arg < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

static int	duplicate_check(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	fill_tab(int *tab, char **args, int size)
{
	int		i;
	int		j;
	char	**joined_args;

	i = 1;
	j = 0;
	while (i < size)
	{
		joined_args = ft_split(args[i], ' ');
		if (!joined_args || range_check(joined_args) == 0)
		{
			if (joined_args)
				free_double_tab(joined_args);
			free(tab);
			return (0);
		}
		fill_tab_bis(joined_args, tab, &j);
		free_double_tab(joined_args);
		i++;
	}
	return (1);
}

int	*error_checker(char **tab, int size, int *tab_len)
{
	int	*result;

	if (digit_check(tab, size) == 0)
		exit(EXIT_FAILURE);
	*tab_len = compute_len(tab, size);
	result = malloc(sizeof(int) * (*tab_len));
	if (!result)
		return (NULL);
	if (fill_tab(result, tab, size) == 0)
		return (NULL);
	if (duplicate_check(result, *tab_len) == 0)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
