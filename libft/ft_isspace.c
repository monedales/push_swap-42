/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:30:49 by mona              #+#    #+#             */
/*   Updated: 2025/09/25 11:33:38 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Check if a character is a whitespace.
 *
 * This function returns 1 if the given character is a whitespace character 
 * (space, tab, newline, vertical tab, form feed, or carriage return).
 * Otherwise, it returns 0.
 *
 * @param chr The character to check.
 * @return 1 if the character is a whitespace, 0 otherwise.
 */
int	ft_isspace(int chr)
{
	if ((chr >= 9 && chr <= 13) || chr == 32)
		return (1);
	return (0);
}