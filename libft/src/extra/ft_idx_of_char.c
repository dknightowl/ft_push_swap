/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idx_of_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:45:17 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/01 23:12:55 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@brief Finds the index of the first occurrence of a character in a
	given null-terminated string

	@param s String to search in
	@param c Character to find the index of in the string

	@return The index of the first occurrence of the character, or
	-1 if it is not found
*/
int	ft_idx_of_char(const char *s, char c)
{
	int	idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}
