/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:04:09 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/19 11:44:46 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ERROR EXIT FUNCTIONS

void	exit_err(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	exit_err_custom(char *err_msg)
{
	ft_printf("%s\n", err_msg);
	exit(EXIT_FAILURE);
}
