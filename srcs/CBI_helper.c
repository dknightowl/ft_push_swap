/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CBI_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:47:24 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 14:07:19 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// HELPERS FOR CBI

void	calc_rotb_cost(t_stack *stack_b, t_cheapest_insert_ctx *ctx)
{
	ctx->rotb_idx = node_index(stack_b, ctx->insert_val);
	ctx->is_rotb_forward = (ctx->rotb_idx) < (int)(stack_b->size / 2);
	if (ctx->is_rotb_forward)
		ctx->rotb_cost = ctx->rotb_idx;
	else
		ctx->rotb_cost = stack_b->size - ctx->rotb_idx;
}

void	calc_rota_cost(t_stack *stack_a, t_cheapest_insert_ctx *ctx)
{
	ctx->is_rota_forward = ctx->tgt_pos < (int)(stack_a->size / 2);
	if (ctx->is_rota_forward)
		ctx->rota_cost = ctx->tgt_pos;
	else
		ctx->rota_cost = stack_a->size - ctx->tgt_pos;
}

void	calc_total_cost(t_cheapest_insert_ctx *ctx)
{
	if (ctx->is_rota_forward == ctx->is_rotb_forward)
	{
		if (ctx->rotb_cost >= ctx->rota_cost)
			ctx->cost = ctx->rotb_cost;
		else if (ctx->rota_cost > ctx->rotb_cost)
			ctx->cost = ctx->rota_cost;
	}
	else
		ctx->cost = ctx->rotb_cost + ctx->rota_cost;
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b, t_cbi_ctx *cbi)
{
	int	is_forward;

	if (cbi->is_rota_forward != cbi->is_rotb_forward)
		return ;
	is_forward = cbi->is_rota_forward;
	if (is_forward)
	{
		while ((stack_a->top->value != cbi->tgt_val)
			&& (stack_b->top->value != cbi->insert_val))
			instruct_rr(stack_a, stack_b);
	}
	else
	{
		while ((stack_a->top->value != cbi->tgt_val)
			&& (stack_b->top->value != cbi->insert_val))
			instruct_rrr(stack_a, stack_b);
	}
}

void	rotate_until(
	t_stack_id id,
	t_stack *stack,
	unsigned int terminate_val,
	int is_forward)
{
	while (stack->top->value != terminate_val)
	{
		if (is_forward)
			instruct_rotate(id, stack);
		else
			instruct_revrotate(id, stack);
	}
}
