/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:54:28 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/26 09:16:23 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// INPUT VALIDATION

static void	exit_err(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

static void	validate_dups(char *psargv[])
{
	int	i_outer;
	int	i_inner;
	int	len_outer;
	int	len_inner;

	i_outer = 0;
	while (psargv[i_outer])
	{
		len_outer = ft_strlen(psargv[i_outer]);
		i_inner = i_outer + 1;
		while (psargv[i_inner])
		{
			len_inner = ft_strlen(psargv[i_inner]);
			if (ft_strncmp(psargv[i_outer], psargv[i_inner], len_outer) == 0
				&& ft_strncmp(psargv[i_outer], psargv[i_inner], len_inner) == 0)
			{
				ft_free2d((void **) psargv);
				exit_err();
			}
			i_inner++;
		}
		i_outer++;
	}
}

static void	validate_ints(char *psargv[])
{
	int		idx;
	char	*endptr;
	long	check_value;

	idx = 0;
	endptr = NULL;
	while (psargv[idx])
	{
		endptr = NULL;
		check_value = ft_strtol(psargv[idx], &endptr, 10);
		if (psargv[idx] == endptr || *endptr != '\0')
		{
			ft_free2d((void **) psargv);
			exit_err();
		}
		if (check_value > INT_MAX || check_value < INT_MIN)
		{
			ft_free2d((void **) psargv);
			exit_err();
		}
		idx++;
	}
}

void	validate_psargv(char *psargv[])
{
	validate_ints(psargv);
	validate_dups(psargv);
}
