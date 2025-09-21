/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CBI.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:19:00 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 14:11:55 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// COST-BASED (RE)INSERTION FROM B TO A

static void	init_findtgt_ctx(t_findtgt_ctx *ctx)
{
	ctx->overall_min = INT_MAX;
	ctx->overall_min_idx = -1;
	ctx->min_greater = INT_MAX;
	ctx->min_greater_idx = -1;
}

static void	set_target(
	t_findtgt_ctx *ctx,
	t_cheapest_insert_ctx *ci_ctx)
{
	if (ctx->min_greater_idx == -1)
	{
		ci_ctx->tgt_pos = ctx->overall_min_idx;
		ci_ctx->tgt_val = ctx->overall_min;
	}
	else
	{
		ci_ctx->tgt_pos = ctx->min_greater_idx;
		ci_ctx->tgt_val = ctx->min_greater;
	}
}

static void	find_target(
	t_stack *stack,
	t_cheapest_insert_ctx *ci_ctx)
{
	t_node			*node;
	t_findtgt_ctx	ctx;
	int				idx;

	node = stack->top;
	ctx = (t_findtgt_ctx){0};
	init_findtgt_ctx(&ctx);
	idx = 0;
	while (node)
	{
		if (node->value < ctx.overall_min)
		{
			ctx.overall_min = node->value;
			ctx.overall_min_idx = idx;
		}
		if ((node->value > ci_ctx->insert_val)
			&& (node->value < ctx.min_greater))
		{
			ctx.min_greater = node->value;
			ctx.min_greater_idx = idx;
		}
		idx++;
		node = node->next;
	}
	set_target(&ctx, ci_ctx);
}

void	calc_cheapest_insert(
	t_stack *stack_a,
	t_stack *stack_b,
	t_cbi_ctx *cbi_ctx)
{
	int						min_cost;
	t_node					*node;
	t_cheapest_insert_ctx	ctx;

	ctx = (t_cheapest_insert_ctx){0};
	min_cost = stack_a->size + stack_b->size;
	node = stack_b->top;
	while (node)
	{
		ctx.insert_val = node->value;
		calc_rotb_cost(stack_b, &ctx);
		find_target(stack_a, &ctx);
		calc_rota_cost(stack_a, &ctx);
		calc_total_cost(&ctx);
		if (ctx.cost < min_cost)
		{
			min_cost = ctx.cost;
			cbi_ctx->insert_val = ctx.insert_val;
			cbi_ctx->tgt_val = ctx.tgt_val;
			cbi_ctx->is_rota_forward = ctx.is_rota_forward;
			cbi_ctx->is_rotb_forward = ctx.is_rotb_forward;
		}
		node = node->next;
	}
}

void	do_cbi(t_stack *stack_a, t_stack *stack_b, t_cbi_ctx *ctx)
{
	if (ctx->is_rota_forward == ctx->is_rotb_forward)
	{
		rotate_both(stack_a, stack_b, ctx);
		rotate_until(STACK_A, stack_a, ctx->tgt_val, ctx->is_rota_forward);
		rotate_until(STACK_B, stack_b, ctx->insert_val, ctx->is_rotb_forward);
	}
	else
	{
		rotate_until(STACK_A, stack_a, ctx->tgt_val, ctx->is_rota_forward);
		rotate_until(STACK_B, stack_b, ctx->insert_val, ctx->is_rotb_forward);
	}
	instruct_push(STACK_A, stack_b, stack_a);
}
