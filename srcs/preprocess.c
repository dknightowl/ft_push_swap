/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:34:59 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 14:30:12 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// PREPROCESS STACK A BEFORE SORTING

static void	populate_stack(t_stack *stack, unsigned int *values, int count)
{
	int	idx;

	idx = count - 1;
	while (idx >= 0)
	{
		push(stack, values[idx]);
		idx--;
	}
}

static int	in_arr(unsigned int *arr, unsigned int value, int arr_size)
{
	int	idx;

	idx = 0;
	while (idx < arr_size)
	{
		if (arr[idx] == value)
			return (1);
		idx++;
	}
	return (0);
}

static void	update_inorder_flags(t_stack *stack, unsigned int *values)
{
	unsigned int	*lis;
	int				lis_len;
	t_node			*node;

	lis = NULL;
	lis_len = 0;
	compute_lis(values, stack->size, &lis, &lis_len);
	if (!lis || lis_len == 0)
		exit(EXIT_FAILURE);
	node = stack->top;
	while (node)
	{
		if (in_arr(lis, node->value, lis_len))
			node->inorder = 1;
		else
			node->inorder = 0;
		node = node->next;
	}
	free(lis);
}

void	init_stack_a(t_stack *stack_a, char *psargv[])
{
	unsigned int	*normalized_inputs;

	normalized_inputs = generate_normalized_inputs(psargv);
	if (!normalized_inputs)
		exit(EXIT_FAILURE);
	populate_stack(stack_a, normalized_inputs, count_args(psargv));
	update_inorder_flags(stack_a, normalized_inputs);
	free(normalized_inputs);
}
