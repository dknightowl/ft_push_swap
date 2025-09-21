/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:27:18 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 14:32:02 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*nxt;

	curr = stack->top;
	while (curr)
	{
		nxt = curr->next;
		free(curr);
		curr = nxt;
	}
	free(stack);
}

void	free_lis_helpers(int *lengths, int *predecessors, unsigned int *lis)
{
	free(lengths);
	free(predecessors);
	free(lis);
}
