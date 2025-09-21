/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 05:52:56 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 15:48:51 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// LONGEST INCREASING SUBSEQUENCE

static unsigned int	*construct_lis(
	int lis_len,
	int *idx_of_max,
	unsigned int *arr,
	const int *predecessors
)
{
	unsigned int	*lis;
	int				idx;

	lis = malloc(lis_len * sizeof(unsigned int));
	if (!lis)
		return (NULL);
	idx = lis_len - 1;
	while ((*idx_of_max) != -1)
	{
		lis[idx] = arr[(*idx_of_max)];
		(*idx_of_max) = predecessors[(*idx_of_max)];
		idx--;
	}
	return (lis);
}

void	compute_lis(
	unsigned int *arr,
	int count,
	unsigned int **lis_out,
	int *lis_len
)
{
	int				*lengths;
	int				*predecessors;
	int				idx_of_max;
	unsigned int	*lis;

	*lis_out = NULL;
	*lis_len = 0;
	if (!allocate_and_init_lis_helpers(count, &lengths, &predecessors))
		return ;
	idx_of_max = update_lis_and_find_max_idx(count, arr, lengths, predecessors);
	*lis_len = lengths[idx_of_max];
	lis = construct_lis(*lis_len, &idx_of_max, arr, predecessors);
	if (!cpy_lis_to_out(lis_out, lis, *lis_len))
	{
		*lis_len = 0;
		return ;
	}
	free_lis_helpers(lengths, predecessors, lis);
}
