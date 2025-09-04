/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:24:48 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/28 16:10:21 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FUNCTIONS TO RETRIEVE STACK PROPERTIES

/**
	@brief Checks if a stack if full

	@param stack Pointer to stack

	@return Some positive integer (system-dependent)
	if the stack is full , else 0.
*/
int	is_full(t_stack *stack)
{
	return (stack->top_idx == (stack->capacity - 1));
}

/**
	@brief Checks if a stack is empty

	@param stack Pointer to stack

	@return Some positive integer (system-dependent)
	if the stack if full, else 0.
*/
int	is_empty(t_stack *stack)
{
	return (stack->top_idx == -1);
}

/**
	@brief Returns top element of the stack without removing it

	@param stack Pointer to stack

	@return Top element of the stack
*/
int	peek(t_stack *stack)
{
	return (stack->array[stack->top_idx]);
}

/**
	@brief Checks whether a stack is sorted in ascending order. If
	sorted, elements should increase from top index (i.e. index at
	the top of the stack) to index 0 (i.e. index at the bottom of the
	stack). Search is conducted from index-n to index 0,

	@param stack Stack to check

	@return 1 if the stack is sorted, 0 if the stack is not sorted
*/
int	is_asc_stack(t_stack *stack)
{
	int	idx;

	if (stack->capacity < 2)
		return (1);
	idx = 0;
	while (idx < stack->top_idx)
	{
		if (stack->array[idx] <= stack->array[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}

int	is_dsc_stack(t_stack *stack)
{
	int	idx;

	if (stack->capacity < 2)
		return (1);
	idx = 0;
	while (idx < stack->top_idx)
	{
		if (stack->array[idx] >= stack->array[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}
