/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:52:31 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 16:23:24 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_psargs(int argc, char *argv[])
{
	int		idx;
	char	*argp;
	int		in_arg;
	int		count;

	idx = 1;
	count = 0;
	while (idx < argc)
	{
		argp = argv[idx];
		in_arg = 0;
		while (*argp)
		{
			if (*argp != ' ' && !in_arg)
			{
				in_arg = 1;
				count++;
			}
			else if (*argp == ' ')
				in_arg = 0;
			argp++;
		}
		idx++;
	}
	return (count);
}

static void	append_to_psargv(char *s, char ***psargv_out, int *curr_idx)
{
	char	**args;
	char	**args_o;

	args = ft_split(s, ' ');
	if (!args)
		return ;
	args_o = args;
	while (*args)
	{
		(*psargv_out)[*curr_idx] = ft_strdup(*args);
		(*curr_idx)++;
		args++;
	}
	ft_free2d((void **) args_o);
}

static char	**parse_psargv(int argc, char *argv[])
{
	char	**psargv;
	int		psargc;
	int		argc_idx;
	int		psargc_idx;

	psargc = count_psargs(argc, argv);
	psargv = malloc((psargc + 1) * sizeof(char *));
	if (!psargv)
		return (NULL);
	argc_idx = 1;
	psargc_idx = 0;
	while (argc_idx < argc)
	{
		append_to_psargv(argv[argc_idx], &psargv, &psargc_idx);
		argc_idx++;
	}
	psargv[psargc_idx] = NULL;
	return (psargv);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort_2(STACK_A, stack_a);
	else if (stack_a->size == 3)
		sort_3(STACK_A, stack_a);
	else if (stack_a->size == 4 || stack_a->size == 5)
		sort_4_5(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	char	**psargv;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit(EXIT_FAILURE);
	psargv = parse_psargv(argc, argv);
	if (!psargv)
		exit(EXIT_FAILURE);
	validate_psargv(psargv);
	stack_a = create_stack();
	init_stack_a(stack_a, psargv);
	stack_b = create_stack();
	if (!is_sorted(stack_a))
		push_swap(stack_a, stack_b);
	free_stack(stack_b);
	free_stack(stack_a);
	ft_free2d((void **) psargv);
	return (0);
}
