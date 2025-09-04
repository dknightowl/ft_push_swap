/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate-input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 08:48:55 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/19 12:55:41 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
	@brief Checks for duplicates in the argument array. If a duplicate
	is found, the program exits with an error message.

	@param argc Number of cmd-line arguments
	@param argv Array of cmd-line arguments
*/
static void	validate_dups(int argc, char *argv[])
{
	int	idx_outer;
	int	idx_inner;
	int	len_outer;
	int	len_inner;

	idx_outer = 1;
	while (idx_outer < argc)
	{
		len_outer = ft_strlen(argv[idx_outer]);
		idx_inner = idx_outer + 1;
		while (idx_inner < argc)
		{
			len_inner = ft_strlen(argv[idx_inner]);
			if (ft_strncmp(argv[idx_outer], argv[idx_inner], len_outer) == 0
				&& ft_strncmp(argv[idx_outer], argv[idx_inner], len_inner) == 0)
				exit_err();
			idx_inner++;
		}
		idx_outer++;
	}
}

/**
	@brief Checks if a string represents the numeric value zero ("0")

	@param value Pointer to null-terminated string

	@return Some positive integer (system-dependent) if the string is
	exactly "0", else 0.
*/
static int	is_zero(char *value)
{
	return (ft_strlen(value) == 1 && *value == '0');
}

/**
	@brief Checks if a string represents a decimal, integer value.
	Valid numeric values consist of a single 0, or an optional
	negative sign followed by one or more digits.

	@param value String to be checked

	@return 1 if string is a valid numeric value, else 0.
*/
static int	is_num(char *value)
{
	if (is_zero(value))
		return (1);
	if (*value == '-')
		value++;
	if (*value == '\0')
		return (0);
	while (*value)
	{
		if (!ft_isdigit(*value))
			return (0);
		value++;
	}
	return (1);
}

/**
	@brief Checks that each argument is a valid integer value. If an
	argument is not a valid integer value, exits with error message.

	@param argc Number of cmd-line arguments
	@param argv Array of cmd-line arguments
*/
static void	validate_ints(int argc, char *argv[])
{
	int		idx;
	char	*endptr;
	long	check_value;

	idx = 1;
	while (idx < argc)
	{
		if (!is_num(argv[idx]))
			exit_err();
		endptr = NULL;
		check_value = ft_strtol(argv[idx], &endptr, 10);
		if (argv[idx] == endptr || *endptr != '\0')
			exit_err();
		if (check_value > INT_MAX || check_value < INT_MIN)
			exit_err();
		idx++;
	}
}

/**
	@brief Validates overall input integrity. Ensures at least one input
	for the stack, arguments are valid integers, and there are no duplicates
	in the stack

	@param argc Number of cmd-line arguments
	@param argv Array of cmd-line arguments
*/
void	validate_input(int argc, char *argv[])
{
	if (argc < 2)
		exit(EXIT_FAILURE);
	validate_ints(argc, argv);
	validate_dups(argc, argv);
}
