/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:37:16 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/16 14:55:59 by acombier         ###   ########.fr       */
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

// Chunks sort utils
size_t	ft_sqrt(int nb);
size_t	calculate_num_chunks(size_t size);
void	find_min_max(t_stack *stack, int *min, int *max);
int calculate_chunk_size(int min, int max, size_t num_chunks);
int is_in_chunk(int value, int min, int chunk_num, int chunk_size);

// Chunks finds
int find_chunk_number(t_stack *a, int min, int chunk_num, int chunk_size);
size_t	find_max_index(t_stack *stack);

// Chunks rotate
void 	rotate_to_top_a(t_stack *a, size_t index);
void	rotate_to_top_b(t_stack *b, size_t index);

// Medium Chunks Algo
void	medium_algo(t_stack *a, t_stack *b);

#endif