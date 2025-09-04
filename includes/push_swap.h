/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:00:28 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/05 01:25:24 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define DEBUG_ON 0

/* libft */
# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "libft.h"
# include "extra.h"

# include <limits.h>
# include <unistd.h> // read, write
# include <stdlib.h> // malloc, free, exit

typedef enum e_reverse_flag
{
	REVERSE_ON = 1,
	REVERSE_OFF = 0,
}	t_reverse_flag;

typedef struct s_stack
{
	int	top_idx; // index of latest element added(-1 indicates it is empty)
	int	capacity; // max. num. of elements stack can hold
	int	*array;	// dynamically-allocated block of memory to store stack elements
}	t_stack;

// error
void	exit_err(void);
void	exit_err_custom(char *err_msg);

// init
t_stack	*create_stack(size_t capacity);
void	init_stack_a(int argc, char *argv[], t_stack **stack_a_ptr);
void	assign_ranks(t_stack **stack_ptr);

// instructs
void	swap_a(t_stack *stack_a, int *cost);
void	swap_b(t_stack *stack_b, int *cost);
void	ss(t_stack *stack_a, t_stack *stack_b, int *cost);
void	push_a(t_stack *stack_b, t_stack *stack_a, int *cost);
void	push_b(t_stack *stack_a, t_stack *stack_b, int *cost);
void	rotate_a(t_stack *stack_a, int *cost);
void	rotate_b(t_stack *stack_b, int *cost);
void	rr(t_stack *stack_a, t_stack *stack_b, int *cost);
void	rev_rotate_a(t_stack *stack_a, int *cost);
void	rev_rotate_b(t_stack *stack_b, int *cost);
void	rrr(t_stack *stack_a, t_stack *stack_b, int *cost);

// log
void	log_stack(t_stack *stack, char *stack_id);
void	log_arr(int *arr, size_t size, char *tag);

// sort-utils
int		find_stack_min_idx(t_stack *stack);
int		idx_of_in_stack(t_stack *stack, int elem);
int		log2_approx(int n);
void	selection_sort_desc(int *arr, int top_idx);
int		calc_batch_size(t_stack *stack);

// sort
void	batch_sort(t_stack *stack_a, int *cost);
void	sort3(t_stack *stack_a, int *cost, t_reverse_flag reversed);
void	sort2(t_stack *stack_a, int *cost);

// stack operations
int		is_full(t_stack *stack);
int		is_empty(t_stack *stack);
int		peek(t_stack *stack);
int		is_asc_stack(t_stack *stack);
int		is_dsc_stack(t_stack *stack);

void	push(t_stack *stack, int elem);
int		pop(t_stack *stack);
void	free_stack(t_stack *stack);

// validate-input
void	validate_input(int argc, char *argv[]);

#endif