/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:54:31 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 15:56:25 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// PUSH_SWAP INSTRUCTION SET FOR BOTH STACK

void	instruct_ss(t_stack *stack1, t_stack *stack2)
{
	swap(stack1);
	swap(stack2);
	ft_printf("ss\n");
}

void	instruct_rr(t_stack *stack1, t_stack *stack2)
{
	rotate(stack1);
	rotate(stack2);
	ft_printf("rr\n");
}

void	instruct_rrr(t_stack *stack1, t_stack *stack2)
{
	reverse_rotate(stack1);
	reverse_rotate(stack2);
	ft_printf("rrr\n");
}
