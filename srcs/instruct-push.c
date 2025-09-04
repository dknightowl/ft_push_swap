/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct-push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:40:47 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/19 13:50:13 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// PUSH INSTRUCTION SET

/**
	@brief Pushes the top element from one stack to another. Top element from
	src_stack is popped and pushed to dst_stack. If src_stack is empty, does
	nothing.

	@param src_stack Source stack
	@param dst_stack Destination stack
*/
static void	push_top_to(t_stack *src_stack, t_stack *dst_stack)
{
	int	push_elem;

	if (is_empty(src_stack))
		return ;
	push_elem = pop(src_stack);
	push(dst_stack, push_elem);
}

/**
	@brief Pushes top element of stack_a to stack_b, increments the operation
	cost, prints the operation name, and logs both stacks if debug mode is on.

	@param stack_b Pointer to stack B
	@param stack_a Pointer to stack A
	@param cost Pointer to operation cost counter
*/
void	push_a(t_stack *stack_b, t_stack *stack_a, int *cost)
{
	push_top_to(stack_b, stack_a);
	*cost += 1;
	ft_printf("pa\n");
	if (DEBUG_ON)
	{
		log_stack(stack_a, "A");
		log_stack(stack_b, "B");
	}
}

/**
	@brief Pushes top element of stack_a to stack_b, increments the operation
	cost, prints the operation name, and logs both stacks if the debug 
	mode is on.

	@param stack_a Pointer to stack A
	@param stack_b Pointer to stack B
	@param cost Pointer to operation cost counter
*/
void	push_b(t_stack *stack_a, t_stack *stack_b, int *cost)
{
	push_top_to(stack_a, stack_b);
	*cost += 1;
	ft_printf("pb\n");
	if (DEBUG_ON)
		log_stack(stack_b, "B");
}
