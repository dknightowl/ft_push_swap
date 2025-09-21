/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:53:27 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 16:26:00 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// GENERAL PURPOSE UTILITIES

size_t	count_args(char *inputs[])
{
	size_t	count;

	count = 0;
	while (inputs[count])
		count++;
	return (count);
}

int	node_index(t_stack *stack, unsigned int value)
{
	int		idx;
	t_node	*node;

	idx = 0;
	node = stack->top;
	while (node != NULL)
	{
		if (node->value == value)
			return (idx);
		idx++;
		node = node->next;
	}
	return (-1);
}

unsigned int	node_value_at(t_stack *stack, int find_idx)
{
	int		idx;
	t_node	*node;

	node = stack->top;
	if (!stack || find_idx < 0 || find_idx > (int)(stack->size - 1))
		return (node->value);
	idx = 0;
	while (node)
	{
		if (idx == find_idx)
			return (node->value);
		idx++;
		node = node->next;
	}
	return (node->value);
}

void	bubble_node(t_stack_id id, t_stack *stack, unsigned int value)
{
	int	node_idx;

	node_idx = node_index(stack, value);
	if (node_idx == -1)
		return ;
	if (node_idx <= (int)(stack->size / 2))
		while (stack->top->value != value)
			instruct_rotate(id, stack);
	else
		while (stack->top->value != value)
			instruct_revrotate(id, stack);
}

int	is_sorted(t_stack *stack)
{
	int		curr;
	int		nxt;
	t_node	*node;

	node = stack->top;
	while (node && node->next)
	{
		curr = node->value;
		nxt = node->next->value;
		if (curr > nxt)
			return (0);
		node = node->next;
	}
	return (1);
}
