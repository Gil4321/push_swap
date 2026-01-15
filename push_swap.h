/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:37:16 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/15 14:48:11 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*array;
	size_t	size;
}			t_stack;

int			*error_checker(char **tab, int size, int *tab_len);
long int	ft_atoi(const char *nptr);
int			ft_strcmp(char *s, char *s2);
int			ft_isdigit(int c);
char		**ft_split(char *s, char c);
size_t		compute_len(char **tab, int size);
void		free_double_tab(char **tab);
void		fill_tab_bis(char **joined_args, int *tab, int *j);
void		simple_algo(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rra(t_stack *a);

#endif