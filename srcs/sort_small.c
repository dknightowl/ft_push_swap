/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:18:13 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 16:26:49 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SORTS STACKS SIZE 2 TO 5

void	sort_2(t_stack_id id, t_stack *stack)
{
	unsigned int	top;
	unsigned int	bottom;

	if (stack->size != 2)
		return ;
	top = stack->top->value;
	bottom = stack->bottom->value;
	if (top > bottom)
		instruct_swap(id, stack);
}

// if (top < middle && middle < bottom)
// 	return ;
void	sort_3(t_stack_id id, t_stack *stack)
{
	unsigned int	top;
	unsigned int	middle;
	unsigned int	bottom;

	if (stack->size != 3)
		return ;
	top = stack->top->value;
	middle = stack->top->next->value;
	bottom = stack->bottom->value;
	if (top > middle && middle < bottom && top < bottom)
		instruct_swap(id, stack);
	else if (top > middle && middle > bottom)
	{
		instruct_swap(id, stack);
		instruct_revrotate(id, stack);
	}
	else if (top > middle && middle < bottom && top > bottom)
		instruct_rotate(id, stack);
	else if (top < middle && middle > bottom && top < bottom)
	{
		instruct_swap(id, stack);
		instruct_rotate(id, stack);
	}
	else if (top < middle && middle > bottom && top > bottom)
		instruct_revrotate(id, stack);
}

static t_node	*find_min_node(t_stack *stack)
{
	t_node	*node;
	t_node	*min;

	node = stack->top;
	min = node;
	while (node)
	{
		if (node->value < min->value)
			min = node;
		node = node->next;
	}
	return (min);
}

void	sort_4_5(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min_node;

	if (stack_a->size < 4 || stack_a->size > 5)
		return ;
	while (stack_a->size > 3)
	{
		min_node = find_min_node(stack_a);
		bubble_node(STACK_A, stack_a, min_node->value);
		instruct_push(STACK_B, stack_a, stack_b);
	}
	sort_3(STACK_A, stack_a);
	while (stack_b->size > 0)
		instruct_push(STACK_A, stack_b, stack_a);
}
