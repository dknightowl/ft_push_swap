/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:57:27 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 16:02:52 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// HELPERS FOR SORT_BIG

int	stack_inorder(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		if (node->inorder == 0)
			return (0);
		node = node->next;
	}
	return (1);
}

int	find_misplaced_idx_top(t_stack *stack)
{
	int		idx;
	t_node	*node;

	idx = 0;
	node = stack->top;
	while (node)
	{
		if (node->inorder == 0)
			return (idx);
		idx++;
		node = node->next;
	}
	return (-1);
}

int	find_misplaced_idx_bottom(t_stack *stack)
{
	int		idx;
	t_node	*node;

	idx = stack->size - 1;
	node = stack->bottom;
	while (node)
	{
		if (node->inorder == 0)
			return (idx);
		idx--;
		node = node->prev;
	}
	return (-1);
}
