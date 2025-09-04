/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:13:25 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/05 01:18:52 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
	@brief Creates a new stack with the given capacity. Allocates memory for a
	new stack and its internal array. Stack's capacity is initialized with the
	given capacity and the top index is set to -1 to indicate an empty array

	@param capacity Maximum number of elements that the stack can hold

	@return Pointer to the newly-created t_stack structure
*/
t_stack	*create_stack(size_t capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		exit_err();
	stack->capacity = capacity;
	stack->top_idx = -1;
	stack->array = malloc(stack->capacity * sizeof(int));
	if (!stack->array)
	{
		free(stack);
		exit_err();
	}
	return (stack);
}

/**
	@brief Initializes stack_a from cmd-line arguments.

	@param argc Argument count from main
	@param argv Argument vector from main
	@param stack_a_ptr Pointer to stack_a struct to be initialized
*/
void	init_stack_a(int argc, char *argv[], t_stack **stack_a_ptr)
{
	t_stack	*stack_a;
	int		idx;

	stack_a = create_stack(argc - 1);
	stack_a->top_idx = stack_a->capacity - 1;
	idx = stack_a->top_idx;
	while (idx >= 0)
	{
		stack_a->array[idx] = ft_atoi(argv[stack_a->top_idx - idx + 1]);
		idx--;
	}
	*stack_a_ptr = stack_a;
}

/**
	@brief Fills ranks array by mapping values in the original stack array
	to its index position in the sorted array

	E.g.	stack_arr	->	[50, 20, 10, 30, 0, 40]
			sorted_arr	->	[50, 40, 30, 20, 10, 0]

			ranks		->	[0, 3, 4, 2, 5, 1]

	Indices are assigned in descending order - from largest value (index 0) to
	smallest value (top_idx)

	@param stack_arr Original stack array
	@param sorted_arr Sorted copy of the stack array
	@param ranks Resulting array to store ranks data
	@param top_idx Index of the top element in the stack
*/
static void	fill_ranks(
	int *stack_arr,
	int *sorted_arr,
	int *ranks,
	int top_idx
)
{
	int	idx;
	int	find;
	int	sorted_idx;

	idx = 0;
	while (idx <= top_idx)
	{
		find = stack_arr[idx];
		sorted_idx = 0;
		while (sorted_idx <= top_idx)
		{
			if (sorted_arr[sorted_idx] == find)
			{
				ranks[idx] = sorted_idx;
				break ;
			}
			sorted_idx++;
		}
		idx++;
	}
}

/**
	@brief Assigns ranks to elements in the stack, replacing the original
	stack values with their relative positions in the stack. Ranks are assigned
	in descending order so the largest value would be ranked 0 and smallest value
	value be ranked (n - 1)

	@param stack_ptr Pointer to stack to update with ranked values
*/
void	assign_ranks(t_stack **stack_ptr)
{
	t_stack	*stack;
	int		*sorted;
	int		*ranks;

	stack = *stack_ptr;
	sorted = malloc(stack->capacity * sizeof(int));
	if (!sorted)
		exit_err();
	ft_memcpy(sorted, stack->array, stack->capacity * sizeof(int));
	selection_sort_desc(sorted, stack->top_idx);
	ranks = malloc(stack->capacity * sizeof(int));
	if (!ranks)
	{
		free(sorted);
		exit_err();
	}
	ft_bzero(ranks, stack->capacity * sizeof(int));
	fill_ranks(stack->array, sorted, ranks, stack->top_idx);
	free(sorted);
	ft_memcpy(stack->array, ranks, stack->capacity * sizeof(int));
	free(ranks);
}
