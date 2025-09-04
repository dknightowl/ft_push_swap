/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-big-utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 06:00:27 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/05 01:25:29 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// UTILITY FUNCTIONS FOR SORTING BIG STACKS

/**
	@brief Finds the index of the minimum element of the stack

	@param stack Pointer to stack

	@return Index of the minimum element. Else, -1 if the stack is empty
*/
int	find_stack_min_idx(t_stack *stack)
{
	int	min_idx;
	int	idx;

	if (is_empty(stack))
		return (-1);
	min_idx = 0;
	idx = min_idx + 1;
	while (idx <= stack->top_idx)
	{
		if (stack->array[idx] < stack->array[min_idx])
			min_idx = idx;
		idx++;
	}
	return (min_idx);
}

int	idx_of_in_stack(t_stack *stack, int elem)
{
	int	idx;

	if (is_empty(stack))
		return (-1);
	idx = 0;
	while (idx <= stack->top_idx)
	{
		if (stack->array[idx] == elem)
			return (idx);
		idx++;
	}
	return (-1);
}

/**
	@brief Replacement function for log2 from <math.h>. Approximates the
	base-2 logarithm of a positive integer.

	@param n Integer to calculate the log base 2 of

	@return Approximate log base 2 of integer n
*/
int	log2_approx(int n)
{
	int	result;

	result = 0;
	while (n > 1)
	{
		n = n >> 1;
		result++;
	}
	return (result);
}

/**
	@brief Sorts integer array in descending order using the selection sort
	algorithm

	@param arr Array to be sorted
	@param top_idx Index of the last element in the array (i.e. top element
	in a stack)
*/
void	selection_sort_desc(int *arr, int top_idx)
{
	int	outer_idx;
	int	inner_idx;
	int	max_idx;
	int	temp;

	outer_idx = 0;
	while (outer_idx <= top_idx)
	{
		max_idx = outer_idx;
		inner_idx = outer_idx + 1;
		while (inner_idx <= top_idx)
		{
			if (arr[inner_idx] > arr[max_idx])
				max_idx = inner_idx;
			inner_idx++;
		}
		temp = arr[outer_idx];
		arr[outer_idx] = arr[max_idx];
		arr[max_idx] = temp;
		outer_idx++;
	}
}

/**
	@brief Calculates batch size for stack processing

	@param stack Pointer to stack

	@return Batch size based on stack's capacity
*/
int	calc_batch_size(t_stack *stack)
{
	return ((int) stack->capacity / log2_approx(stack->capacity));
}
