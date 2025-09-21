/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:52:54 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 16:23:07 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// NORMALIZE INPUT VALUES FOR STACK A BEFORE SORTING

static void	selection_sort_asc(int *values, int size)
{
	int	curr_idx;
	int	compare_idx;
	int	idx_of_min;
	int	tmp;

	curr_idx = 0;
	while (curr_idx < size)
	{
		idx_of_min = curr_idx;
		compare_idx = curr_idx + 1;
		while (compare_idx < size)
		{
			if (values[compare_idx] < values[idx_of_min])
				idx_of_min = compare_idx;
			compare_idx++;
		}
		tmp = values[curr_idx];
		values[curr_idx] = values[idx_of_min];
		values[idx_of_min] = tmp;
		curr_idx++;
	}
}

static void	fill_ranks(
	int *values,
	int *sorted,
	unsigned int *ranks,
	size_t size
)
{
	size_t	idx;
	int		find;
	size_t	sorted_idx;

	idx = 0;
	while (idx < size)
	{
		find = values[idx];
		sorted_idx = 0;
		while (sorted_idx < size)
		{
			if (sorted[sorted_idx] == find)
			{
				ranks[idx] = sorted_idx;
				break ;
			}
			sorted_idx++;
		}
		idx++;
	}
}

unsigned int	*generate_normalized_inputs(char *psargv[])
{
	size_t				count;
	int					*values;
	int					*sorted_values;
	size_t				idx;
	unsigned int		*normalized_inputs;

	count = count_args(psargv);
	values = malloc(count * sizeof(int));
	sorted_values = malloc(count * sizeof(int));
	normalized_inputs = malloc(count * sizeof(unsigned int));
	if (!values || !sorted_values || !normalized_inputs)
		return (NULL);
	idx = 0;
	while (idx < count)
	{
		values[idx] = ft_atoi(psargv[idx]);
		idx++;
	}
	ft_memcpy(sorted_values, values, count * sizeof(int));
	selection_sort_asc(sorted_values, count);
	fill_ranks(values, sorted_values, normalized_inputs, count);
	free(values);
	free(sorted_values);
	return (normalized_inputs);
}
