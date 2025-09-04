/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack-write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:22:00 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/19 12:00:59 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// OPERATIONS TO MODIFY STACK

/**
	@brief Pushes an element onto the provided stack. If the
	stack is already full, nothing is done to prevent a stack
	overflow.

	@param stack Pointer to the stack
	@param elem Element to push
*/
void	push(t_stack *stack, int elem)
{
	if (is_full(stack))
		return ;
	stack->top_idx += 1;
	stack->array[stack->top_idx] = elem;
}

/**
	@brief Pops the top element from the provided stack. If the
	stack is empty, the program exits to prevent a stack underflow.

	@param stack Pointer to stack

	@return The popped element
*/
int	pop(t_stack *stack)
{
	if (is_empty(stack))
		exit_err();
	return (stack->array[stack->top_idx--]);
}

/**
	@brief Frees memory allocated to the stack and its internal array

	@param stack Pointer to stack
*/
void	free_stack(t_stack *stack)
{
	if (stack)
	{
		free(stack->array);
		free(stack);
	}
}
