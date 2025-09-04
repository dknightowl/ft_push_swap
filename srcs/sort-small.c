/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:20:29 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/24 09:02:53 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_stack_order(
	t_stack *stack,
	t_reverse_flag reversed,
	int *bottom,
	int *top
){
	if (reversed == REVERSE_ON)
	{
		*bottom = stack->array[0];
		*top = stack->array[2];
	}
	else
	{
		*top = stack->array[0];
		*bottom = stack->array[2];
	}
}

/**
	@brief Sorts a stack of size 3. Sorting logic can be reversed via
	reversed flag. If reverse flag is set to REVERSE_ON, the index 0
	represents the bottom of the stack and index 2 represents the top.
	Else, it is reversed.

	Orderings and their corresponding operations:
	[3, 2, 1] -> swap, reverse rotate
	[3, 1, 2] -> rotate
	[2, 3, 1] -> reverse rotate
	[2, 1, 3] -> swap
	[1, 2, 3] -> (do nothing)
	[1, 3, 2] -> swap, rotate

	@param stack_a Pointer to the stack A - i.e. the stack to be sorted
	@param cost Pointer to operation cost counter
	@param reversed Flag indicating whether to reverse stack order
*/
void	sort3(t_stack *stack_a, int *cost, t_reverse_flag reversed)
{
	int	bottom;
	int	middle;
	int	top;

	assign_stack_order(stack_a, reversed, &bottom, &top);
	middle = stack_a->array[1];
	if (bottom > middle && middle > top && bottom > top)
	{
		swap_a(stack_a, cost);
		rev_rotate_a(stack_a, cost);
	}
	else if (bottom > middle && middle < top && bottom > top)
		rotate_a(stack_a, cost);
	else if (bottom < middle && middle > top && bottom > top)
		rev_rotate_a(stack_a, cost);
	else if (bottom > middle && middle < top && bottom < top)
		swap_a(stack_a, cost);
	else if (bottom < middle && middle > top && bottom < top)
	{
		swap_a(stack_a, cost);
		rotate_a(stack_a, cost);
	}
}

//TODO: add reverse flag
/**
	@brief Sorts a stack of size 2

	@param stack_a Pointer to stack A - i.e. the stack to be sorted
	@param cost Pointer to operation cost counter
*/
void	sort2(t_stack *stack_a, int *cost)
{
	int	top;
	int	bottom;

	top = stack_a->array[0];
	bottom = stack_a->array[1];
	if (bottom > top)
		swap_a(stack_a, cost);
}
