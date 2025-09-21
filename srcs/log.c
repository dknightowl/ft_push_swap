/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:15:47 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/21 16:26:59 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_args(char *psargv[])
{
	int	i;

	i = 0;
	ft_printf("psargv: ");
	while (psargv[i] != NULL)
	{
		ft_printf("(%s) ", psargv[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_stack(t_stack *stack)
{
	t_node	*node;

	if (!stack)
	{
		ft_printf("(null stack)\n");
		return ;
	}
	node = stack->top;
	while (node)
	{
		ft_printf("{ value: %u, inorder: %u } \n", node->value, node->inorder);
		node = node->next;
	}
	ft_printf("\n");
}

void	print_cbi_ctx(t_cbi_ctx *cbi)
{
	ft_printf("\n");
	if (!cbi)
	{
		ft_printf("(null cbi)\n");
		return ;
	}
	ft_printf("CBI: ");
	ft_printf("{insert_val: %u, ", cbi->insert_val);
	ft_printf("tgt_val: %u, ", cbi->tgt_val);
	ft_printf("is_rotb_forward: %d, ", cbi->is_rotb_forward);
	ft_printf("is_rota_forward: %d }\n", cbi->is_rota_forward);
}
