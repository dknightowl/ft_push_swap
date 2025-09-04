/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:46:39 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/24 16:14:45 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* LOGGING FUNCTIONS FOR DEVELOPMENT PURPOSES */

void	log_stack(t_stack *stack, char *stack_id)
{
	if (!stack)
	{
		ft_printf("Stack pointer is NULL\n");
		return ;
	}
	ft_printf("Stack %s:\n", stack_id);
	ft_printf("  Capacity: %d\n", stack->capacity);
	ft_printf("  Top Index: %d\n", stack->top_idx);
	if (!stack->array)
	{
		ft_printf("  Array pointer is NULL\n");
		return ;
	}
	if (stack->top_idx == -1)
	{
		ft_printf("  (empty)\n");
		return ;
	}
	log_arr(stack->array, stack->top_idx + 1, "  Elements (top to bottom)");
}

void	log_arr(int *arr, size_t size, char *tag)
{
	int	idx;

	idx = (int) size - 1;
	ft_printf("%s\n", tag);
	while (idx >= 0)
	{
		ft_printf("    [%03d]: %d\n", idx, arr[idx]);
		idx--;
	}
	ft_printf("\n");
}
