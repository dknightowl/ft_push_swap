/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct-revrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:42:30 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/19 13:50:25 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// REVERSE ROTATE INSTRUCTION SET

/**
	@brief Rotates a stack downward (i.e. in reverse) by shifting all elements
	down by one position. Elements move towards the position of the bottom
	element (top_idx to 0)

	@param stack Pointer to stack
*/
static void	rev_rotate(t_stack *stack)
{
	int		bottom_elem;
	int		idx;

	if (stack->top_idx < 1)
		return ;
	bottom_elem = stack->array[0];
	idx = 0;
	while (idx < stack->top_idx)
	{
		stack->array[idx] = stack->array[idx + 1];
		idx++;
	}
	stack->array[stack->top_idx] = bottom_elem;
}

/**
	@brief Rotates stack_a downwards, increments the operation cost, prints
	the operation name, and logs the stack if debug mode is on

	@param stack_a Pointer to stack A
	@param cost Pointer to operation cost counter
*/
void	rev_rotate_a(t_stack *stack_a, int *cost)
{
	rev_rotate(stack_a);
	*cost += 1;
	ft_printf("rra\n");
	if (DEBUG_ON)
		log_stack(stack_a, "A");
}

/**
	@brief Rotates stack_b downwards, increments the operation cost, prints
	the operation name, and logs the stack if debug mode is on

	@param stack_b Pointer to stack B
	@param cost Pointer to operation cost counter
*/
void	rev_rotate_b(t_stack *stack_b, int *cost)
{
	rev_rotate(stack_b);
	*cost += 1;
	ft_printf("rrb\n");
	if (DEBUG_ON)
		log_stack(stack_b, "B");
}

/**
	@brief Rotates both stack_a and stack_b downwards

	@param stack_a Pointer to stack_a
	@param stack_b Pointer to stack_b
	@param cost Pointer to operation cost counter
*/
void	rrr(t_stack *stack_a, t_stack *stack_b, int *cost)
{
	rev_rotate_a(stack_a, cost);
	rev_rotate_b(stack_b, cost);
}
