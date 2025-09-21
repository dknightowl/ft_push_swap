/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 02:59:54 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 16:26:35 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// EXTENDED STACK OPERATIONS (SPECIFIC TO PUSH_SWAP)

void	swap(t_stack *stack)
{
	t_node	*top;
	t_node	*second;

	if (stack->size < 2)
		return ;
	top = stack->top;
	second = top->next;
	top->next = second->next;
	if (second->next)
		second->next->prev = top;
	else
		stack->bottom = top;
	second->prev = NULL;
	second->next = top;
	top->prev = second;
	stack->top = second;
}

void	rotate(t_stack *stack)
{
	t_node	*top_orig;

	if (!stack || stack->size < 2)
		return ;
	top_orig = stack->top;
	stack->top = top_orig->next;
	stack->top->prev = NULL;
	top_orig->next = NULL;
	top_orig->prev = stack->bottom;
	stack->bottom->next = top_orig;
	stack->bottom = top_orig;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*bottom;

	if (stack->size < 2)
		return ;
	bottom = stack->bottom;
	stack->bottom = bottom->prev;
	stack->bottom->next = NULL;
	bottom->prev = NULL;
	bottom->next = stack->top;
	stack->top->prev = bottom;
	stack->top = bottom;
}

void	push_to(t_stack *src, t_stack *dst)
{
	t_node	*node;

	if (src->size == 0)
		return ;
	node = src->top;
	src->top = node->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	src->size--;
	node->prev = NULL;
	node->next = dst->top;
	if (dst->top)
		dst->top->prev = node;
	else
		dst->bottom = node;
	dst->top = node;
	dst->size++;
}
