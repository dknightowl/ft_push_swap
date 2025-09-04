/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct-swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:15:00 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/19 13:49:50 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ALLOWED INSTRUCTION SET */

/**
	@brief Swap the top two elements of the stack if it contains at least
	two elements

	@param stack Pointer to stack
*/
static void	swap_top(t_stack *stack)
{
	int	temp;

	if (stack->top_idx > 0)
	{
		temp = stack->array[stack->top_idx];
		stack->array[stack->top_idx] = stack->array[stack->top_idx - 1];
		stack->array[stack->top_idx - 1] = temp;
	}
}

/**
	@brief Swaps the top two elements of stack_a, increments the operation cost,
	prints the operation name, and logs the stack if debug mode is on.

	@param stack_a Pointer to stack A
	@param cost Pointer to operation cost counter
*/
void	swap_a(t_stack *stack_a, int *cost)
{
	swap_top(stack_a);
	*cost += 1;
	ft_printf("sa\n");
	if (DEBUG_ON)
		log_stack(stack_a, "A");
}

/**
	@brief Swap the top two elements of stack_b, increments the operation cost,
	prints the operation name, and logs the stack if debug mode is on

	@param stack_b Pointer to stack B
	@param cost Pointer to operation cost counter
*/
void	swap_b(t_stack *stack_b, int *cost)
{
	swap_top(stack_b);
	*cost += 1;
	ft_printf("sb\n");
	if (DEBUG_ON)
		log_stack(stack_b, "B");
}

/**
	@brief Swaps the top two elements of both stack_a and stack_b

	@param stack_a Pointer to stack A
	@param stack_b Pointer to stack B
	@param cost Pointer to operation cost counter
*/
void	ss(t_stack *stack_a, t_stack *stack_b, int *cost)
{
	swap_a(stack_a, cost);
	swap_b(stack_b, cost);
}
