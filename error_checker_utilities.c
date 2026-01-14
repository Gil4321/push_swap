/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker_utilities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:08:31 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/12 16:23:57 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

long int	ft_atoi(const char *nptr)
{
	size_t		i;
	int			negative;
	long int	result;

	i = 0;
	negative = 1;
	result = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			negative *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	result *= negative;
	return (result);
}

size_t	compute_len(char **tab, int size)
{
	int		i;
	size_t	len;

	i = 1;
	len = 0;
	while (i < size)
	{
		len += word_count(tab[i], ' ');
		i++;
	}
	return (len);
}

void	free_double_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	fill_tab_bis(char **joined_args, int *tab, int *j)
{
	int	k;

	k = 0;
	while (joined_args[k])
	{
		tab[(*j)] = ft_atoi(joined_args[k]);
		(*j)++;
		k++;
	}
}
