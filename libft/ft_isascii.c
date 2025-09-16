/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:57:50 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/16 17:26:20 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Checks whether a character is part of the ASCII set.
 *
 * This function checks if the given character c is part of
 * the standard ASCII table (values from 0 to 127).
 *
 * @param chr The character to check.
 * @return Non-zero if c is in the ASCII set, zero otherwise.
 */
int	ft_isascii(int chr)
{
	if (chr >= 0 && chr <= 127)
		return (1);
	else
		return (0);
}
