/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:49:31 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 16:03:50 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* libft */
# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "libft.h"
# include "extra.h"

# include <limits.h>
# include <unistd.h> // read, write
# include <stdlib.h> // malloc, free, exit

typedef enum e_stack_id
{
	STACK_A,
	STACK_B
}	t_stack_id;

typedef struct s_node
{
	unsigned int	value;
	unsigned int	inorder; // flags whether value is in order or not
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

// doubly-linked list
typedef struct s_stack
{
	t_node	*top; // top of stack
	t_node	*bottom; // bottom of stack
	size_t	size; // stack size
}	t_stack;

// variables for finding target for cost-based reinsertion
typedef struct s_findtgt_ctx
{
	unsigned int	overall_min;
	unsigned int	min_greater;
	int				overall_min_idx;
	int				min_greater_idx;
}	t_findtgt_ctx;

// variables for calculating cheapest insertion
typedef struct s_cheapest_insert
{
	unsigned int	insert_val;
	int				rotb_idx;
	int				is_rotb_forward;
	int				rotb_cost;
	int				tgt_pos;
	unsigned int	tgt_val;
	int				is_rota_forward;
	int				rota_cost;
	int				cost;
}	t_cheapest_insert_ctx;

// variables for cost-based (re)insertion
typedef struct s_cbi
{
	unsigned int	insert_val;
	unsigned int	tgt_val;
	int				is_rotb_forward;
	int				is_rota_forward;
}	t_cbi_ctx;

// CBI
void			calc_rotb_cost(t_stack *stack_b, t_cheapest_insert_ctx *ctx);
void			calc_rota_cost(t_stack *stack_a, t_cheapest_insert_ctx *ctx);
void			calc_total_cost(t_cheapest_insert_ctx *ctx);
void			rotate_both(t_stack *stack_a, t_stack *stack_b, t_cbi_ctx *cbi);
void			rotate_until(
					t_stack_id id,
					t_stack *stack,
					unsigned int terminate_val,
					int is_forward);
void			calc_cheapest_insert(
					t_stack *stack_a,
					t_stack *stack_b,
					t_cbi_ctx *cbi);
void			do_cbi(t_stack *stack_a, t_stack *stack_b, t_cbi_ctx *vars);

// create
t_stack			*create_stack(void);
t_node			*create_node(unsigned int value);

// instruct
void			instruct_swap(t_stack_id id, t_stack *stack);
void			instruct_ss(t_stack *stack1, t_stack *stack2);
void			instruct_push(t_stack_id dst_id, t_stack *src, t_stack *dst);
void			instruct_rotate(t_stack_id id, t_stack *stack);
void			instruct_rr(t_stack *stack1, t_stack *stack2);
void			instruct_revrotate(t_stack_id id, t_stack *stack);
void			instruct_rrr(t_stack *stack1, t_stack *stack2);

// LIS
int				allocate_and_init_lis_helpers(
					int count,
					int **lengths,
					int **predecessors);
int				cpy_lis_to_out(
					unsigned int **lis_out,
					unsigned int *lis,
					int lis_len);
int				update_lis_and_find_max_idx(
					int count,
					unsigned int *arr,
					int *lengths,
					int *predecessors);
void			compute_lis(
					unsigned int *arr,
					int count,
					unsigned int **lis_out,
					int *lis_len);

// log
void			print_args(char *psargv[]);
void			print_stack(t_stack *stack);
void			print_cbi_ctx(t_cbi_ctx *cbi);

// free
void			free_stack(t_stack *stack);
void			free_lis_helpers(
					int *lengths,
					int *predecessors,
					unsigned int *lis);

// normalize
unsigned int	*generate_normalized_inputs(char *inputs[]);

// preprocess
void			init_stack_a(t_stack *stack_a, char *inputs[]);

// sort_big
void			sort_big(t_stack *stack_a, t_stack *stack_b);
int				stack_inorder(t_stack *stack);
int				find_misplaced_idx_top(t_stack *stack);
int				find_misplaced_idx_bottom(t_stack *stack);

// sort_small
void			sort_2(t_stack_id id, t_stack *stack);
void			sort_3(t_stack_id id, t_stack *stack);
void			sort_4_5(t_stack *stack_a, t_stack *stack_b);

// stack_ops_extra
void			swap(t_stack *stack);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);
void			push_to(t_stack *src, t_stack *dst);

// stack_ops_std
void			push(t_stack *stack, unsigned int value);
unsigned int	pop(t_stack *stack);
unsigned int	peek(t_stack *stack);

// utils
size_t			count_args(char *inputs[]);
int				node_index(t_stack *stack, unsigned int value);
unsigned int	node_value_at(t_stack *stack, int find_idx);
void			bubble_node(t_stack_id id, t_stack *stack, unsigned int value);
int				is_sorted(t_stack *stack);
char			**ft_subarr(char **arr, size_t start, size_t length);

// validate
void			validate_psargv(char *psargv[]);

#endif