/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct-rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:40:12 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/19 13:50:06 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ROTATE INSTRUCTION SET

/**
	@brief Rotates a stack upward by shifting all elements in the stack
	up by one position. Elements move towards the position of the top
	element (0 to top_idx)

	@param stack Pointer to the stack
*/
static void	rotate(t_stack *stack)
{
	int	top_elem;
	int	idx;

	if (stack->top_idx < 1)
		return ;
	top_elem = stack->array[stack->top_idx];
	idx = stack->top_idx;
	while (idx > 0)
	{
		stack->array[idx] = stack->array[idx - 1];
		idx--;
	}
	stack->array[0] = top_elem;
}

/**
	@brief Rotates stack_a upward, increments the operation cost,
	and prints the operation name, and logs the stack if debug mode is on

	@param stack_a Pointer to stack A
	@param cost Pointer to operation cost counter
*/
void	rotate_a(t_stack *stack_a, int *cost)
{
	rotate(stack_a);
	*cost += 1;
	ft_printf("ra\n");
	if (DEBUG_ON)
		log_stack(stack_a, "A");
}

/**
	@brief Rotates stack_b upward, increments the operation cost, prints the
	operation name, and logs the stack if debug mode is on

	@param stack_b Pointer to stack B
	@param cost Pointer to operation cost counter
*/
void	rotate_b(t_stack *stack_b, int *cost)
{
	rotate(stack_b);
	*cost += 1;
	ft_printf("rb\n");
	if (DEBUG_ON)
		log_stack(stack_b, "B");
}

/**
	@brief Rotates both stack_a and stack_b

	@param stack_a Pointer to stack A
	@param stack_b Pointer to stack B
	@param cost Pointer to operation cost counter
*/
void	rr(t_stack *stack_a, t_stack *stack_b, int *cost)
{
	rotate_a(stack_a, cost);
	rotate_b(stack_b, cost);
}
