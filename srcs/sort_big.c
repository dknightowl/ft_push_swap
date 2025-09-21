/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 05:42:03 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 16:06:24 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	find_next_misplaced(t_stack *stack)
{
	int		top_idx;
	int		bottom_idx;

	top_idx = find_misplaced_idx_top(stack);
	bottom_idx = find_misplaced_idx_bottom(stack);
	if (top_idx < ((int) stack->size - bottom_idx))
		return (node_value_at(stack, top_idx));
	return (node_value_at(stack, bottom_idx));
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	t_cbi_ctx		*cbi;
	int				min_idx;

	while (!stack_inorder(stack_a))
	{
		bubble_node(STACK_A, stack_a, find_next_misplaced(stack_a));
		instruct_push(STACK_B, stack_a, stack_b);
	}
	cbi = malloc(sizeof(t_cbi_ctx));
	if (!cbi)
		return ;
	while (stack_b->size > 0)
	{
		calc_cheapest_insert(stack_a, stack_b, cbi);
		do_cbi(stack_a, stack_b, cbi);
	}
	free(cbi);
	min_idx = node_index(stack_a, 0);
	if (min_idx < (int)(stack_a->size / 2))
		while (stack_a->top->value != 0)
			instruct_rotate(STACK_A, stack_a);
	else
		while (stack_a->top->value != 0)
			instruct_revrotate(STACK_A, stack_a);
}
