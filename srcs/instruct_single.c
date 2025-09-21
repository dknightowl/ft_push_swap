/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_single.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 03:03:07 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 15:55:59 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// PUSH_SWAP INSTRUCTION SET FOR SINGLE STACK

void	instruct_swap(t_stack_id id, t_stack *stack)
{
	swap(stack);
	if (id == STACK_A)
		ft_printf("sa\n");
	else if (id == STACK_B)
		ft_printf("sb\n");
}

void	instruct_push(t_stack_id dst_id, t_stack *src, t_stack *dst)
{
	push_to(src, dst);
	if (dst_id == STACK_A)
		ft_printf("pa\n");
	else if (dst_id == STACK_B)
		ft_printf("pb\n");
}

void	instruct_rotate(t_stack_id id, t_stack *stack)
{
	rotate(stack);
	if (id == STACK_A)
		ft_printf("ra\n");
	else if (id == STACK_B)
		ft_printf("rb\n");
}

void	instruct_revrotate(t_stack_id id, t_stack *stack)
{
	reverse_rotate(stack);
	if (id == STACK_A)
		ft_printf("rra\n");
	else if (id == STACK_B)
		ft_printf("rrb\n");
}
