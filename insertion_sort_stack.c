void	insertion_sort_stack(t_stack **stack_a, t_stack **stack_b, int *cost)
{
	int	next_stack_min;

	next_stack_min = 0;

	while (next_stack_min < (*stack_a)->capacity)
	{

		// next_min is at the top -> lock it in place
		if (peek(*stack_a) == next_stack_min)
			next_stack_min++;

		// next_min is deeper in A -> rotate until it is found
		else if (idx_of_in_stack(*stack_a, next_stack_min) != -1)
		{
			// ft_printf("min:%d, idx in A: %d\n", next_stack_min,  idx_of_in_stack(*stack_a, next_stack_min));
			while (peek(*stack_a) != next_stack_min)
			{
				rev_rotate_a(*stack_a, cost);
				if (peek(*stack_a) != next_stack_min)
					push_b(*stack_a, *stack_b, cost);
			}
			next_stack_min++;
		}

		// next_min is not in A -> search in B
		else
		{
			int next_stack_min_idx = idx_of_in_stack(*stack_b, next_stack_min);

			if (next_stack_min_idx <= ((*stack_b)->top_idx / 2))
			{
				while (peek(*stack_b) != next_stack_min)
					rotate_b(*stack_b, cost);
			}
			else
				while (peek(*stack_b) != next_stack_min)
					rev_rotate_b(*stack_b, cost);

			push_a(*stack_b, *stack_a, cost);
			next_stack_min++;
		}
	}
}
