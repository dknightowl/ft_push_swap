/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:26:10 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/05 01:02:19 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
	@brief Finds the index next element in the stack within the batch's
	upper bound. The lower bound of the batch need not be specified as
	the batching is done incrementally.

	@param stack Pointer to the stack
	@param batch_upper_bound Upper bound of the current batch

	@return Index of the next qualifying element, or -1 if the element
	cannot be found
*/
int	find_next_batch_idx(t_stack *stack, int batch_upper_bound)
{
	size_t	size;
	size_t	idx;

	size = stack->top_idx + 1;
	idx = 0;
	while (idx < size)
	{
		if (stack->array[idx] <= batch_upper_bound)
			return (idx);
		idx++;
	}
	return (-1);
}

void	half_sort_a(t_stack **stack_a, t_stack **stack_b, int *cost)
{
	while ((*stack_a)->top_idx > ((*stack_a)->capacity / 2))
	{
		if (peek(*stack_a) < ((*stack_a)->capacity / 2))
			push_b(*stack_a, *stack_b, cost);
		else
			rotate_a(*stack_a, cost);
	}
	while (!is_empty(*stack_b))
		push_a(*stack_b, *stack_a, cost);
}

/**
	@brief Moves elements from stack_a to stack_b in batches based on
	their ranks. Elements are pushed to stack_b in incrementing batches
	to help optimize later sorting steps.

	@param stack_a Double pointer to stack_a (source stack)
	@param stack_b Double pointer to stack_b (destination stack)
	@param cost Pointer to cost counter for operations performed
*/
void	batch_move_to_b(t_stack **stack_a, t_stack **stack_b, int *cost)
{
	int	batch_size;
	int	batch_upper_bound;
	int	next_idx;

	batch_size = calc_batch_size(*stack_a);
	batch_upper_bound = batch_size - 1;
	while ((*stack_a)->top_idx >= 0)
	{
		if (peek(*stack_a) <= batch_upper_bound)
		{
			push_b(*stack_a, *stack_b, cost);
			if (peek(*stack_b) < ((*stack_b)->top_idx / 2))
				rotate_b(*stack_b, cost);
		}
		else
		{
			next_idx = find_next_batch_idx(*stack_a, batch_upper_bound);
			if (next_idx > ((*stack_a)->top_idx / 2))
				rotate_a(*stack_a, cost);
			else if (next_idx != -1 && next_idx <= ((*stack_a)->top_idx / 2))
				rev_rotate_a(*stack_a, cost);
		}
		if ((*stack_b)->top_idx == batch_upper_bound || next_idx == -1)
			batch_upper_bound += batch_size;
	}
}

/**
	@brief Moves elements from stack_b to stack_a in ascending order. The
	minimum element in stack_b is repeatedly floated to the top, then pushed to
	stack_a to construct the sorted stack.

	@param stack_b Double pointer to stack_b (source stack)
	@param stack_a Double pointer to stack_a (destination stack)
	@param cost Pointer to cost counter for operations performed
*/
void	sort_move_to_a(t_stack **stack_b, t_stack **stack_a, int *cost)
{
	int	idxof_b_min;
	int	b_min;

	while (!is_empty(*stack_b))
	{
		idxof_b_min = find_stack_min_idx(*stack_b);
		b_min = (*stack_b)->array[idxof_b_min];
		if (idxof_b_min > ((*stack_b)->top_idx / 2))
		{
			while (peek(*stack_b) != b_min)
				rotate_b(*stack_b, cost);
		}
		else
		{
			while (peek(*stack_b) != b_min)
				rev_rotate_b(*stack_b, cost);
		}
		push_a(*stack_b, *stack_a, cost);
	}
}

/**
	@brief Sorts a stack using an batch-based sorting algorithm

	The algorithm works in two phases:
	1. Move elements from stack_a to stack_b in batches based on their ranks data
	- which should already be initialized in stack_a
	2. Move elements back from stack_b to stack_a in ascending order to create
	the final sorted stack

	@param stack_a Pointer to stack to be sorted
	@param cost Pointer to cost counter for operations performed
*/
void	batch_sort(t_stack *stack_a, int *cost)
{
	t_stack	*stack_b;

	stack_b = create_stack(stack_a->capacity);
	half_sort_a(&stack_a, &stack_b, cost);
	batch_move_to_b(&stack_a, &stack_b, cost);
	sort_move_to_a(&stack_b, &stack_a, cost);
	free_stack(stack_b);
}
