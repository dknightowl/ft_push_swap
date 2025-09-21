/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_std.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:54:13 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/19 18:23:43 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// STANDARD STACK OPERATIONS

void	push(t_stack *stack, unsigned int value)
{
	t_node	*node;

	node = create_node(value);
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->next = stack->top;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

unsigned int	pop(t_stack *stack)
{
	t_node			*top;
	unsigned int	value;

	if (stack->size == 0)
		exit(EXIT_FAILURE);
	top = stack->top;
	value = top->value;
	stack->top = top->next;
	if (stack->top)
		stack->top->prev = NULL;
	else
		stack->bottom = NULL;
	free(top);
	stack->size--;
	return (value);
}

unsigned int	peek(t_stack *stack)
{
	if (stack->size == 0)
		exit(EXIT_FAILURE);
	return (stack->top->value);
}
