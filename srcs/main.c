/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:03:13 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/19 13:49:00 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack *stack_a, int *cost)
{
	assign_ranks(&stack_a);
	if (stack_a->capacity == 2)
		sort2(stack_a, cost);
	else if (stack_a->capacity == 3)
		sort3(stack_a, cost, REVERSE_OFF);
	else if (stack_a->capacity > 3)
		batch_sort(stack_a, cost);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	int		cost;
	int		sorted;

	validate_input(argc, argv);
	init_stack_a(argc, argv, &stack_a);
	cost = 0;
	sorted = is_asc_stack(stack_a);
	if (!sorted)
		push_swap(stack_a, &cost);
	free_stack(stack_a);
	return (0);
}
