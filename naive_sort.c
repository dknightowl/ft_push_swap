void	naive_sort(t_stack **stack_a, t_stack **stack_b, int *cost)
{
	while (!is_empty(*stack_a))
	{
		int max_idx = find_stack_max_idx(*stack_a);

		if (max_idx == (*stack_a)->top_idx)
			push_b(*stack_a, *stack_b, cost);
		else
			rotate_a(*stack_a, cost);
	}

	while (!is_empty(*stack_b))
		push_a(*stack_b, *stack_a, cost);
}
