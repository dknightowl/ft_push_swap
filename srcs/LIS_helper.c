/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:19:16 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 15:46:54 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// HELPERS FOR LIS

static void	fill_ints(int *arr, int value, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		arr[idx] = value;
		idx++;
	}
}

static void	update_lis(
	int curr_idx,
	unsigned int *arr,
	int *lis_lengths,
	int *lis_predecessors
)
{
	int	idx;

	idx = 0;
	while (idx < curr_idx)
	{
		if (
			(arr[idx] < arr[curr_idx])
			&& ((lis_lengths[idx] + 1) > lis_lengths[curr_idx])
		)
		{
			lis_lengths[curr_idx] = lis_lengths[idx] + 1;
			lis_predecessors[curr_idx] = (int) idx;
		}
		idx++;
	}
}

int	allocate_and_init_lis_helpers(int count, int **lengths, int **predecessors)
{
	*lengths = malloc(count * sizeof(int));
	*predecessors = malloc(count * sizeof(int));
	if (!*lengths || !*predecessors)
	{
		free_lis_helpers(*lengths, *predecessors, NULL);
		return (0);
	}
	fill_ints(*lengths, 1, count);
	fill_ints(*predecessors, -1, count);
	return (1);
}

int	update_lis_and_find_max_idx(
	int count,
	unsigned int *arr,
	int *lengths,
	int *predecessors)
{
	int	max_idx;
	int	idx;

	max_idx = 0;
	idx = 1;
	while (idx < count)
	{
		update_lis(idx, arr, lengths, predecessors);
		if (lengths[idx] > lengths[max_idx])
			max_idx = idx;
		idx++;
	}
	return (max_idx);
}

int	cpy_lis_to_out(unsigned int **lis_out, unsigned int *lis, int lis_len)
{
	*lis_out = malloc(lis_len * sizeof(unsigned int));
	if (!*lis_out)
		return (0);
	ft_memcpy(*lis_out, lis, lis_len * sizeof(unsigned int));
	return (1);
}
