/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:03:35 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/15 21:35:42 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief checks whether a character is alphanumeric.
 *
 * The function checks if the given character c is an
 * alphanumeric character, either a letter or a digit.
 *
 * @param chr The character to be checked.
 * @return the values returned are nonzero if the character 
 * c falls into an alphanumeric character, zero otherwise.
 */
int	ft_isalnum(int chr)
{
	if (((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'))
		|| (chr >= '0' && chr <= '9'))
		return (1);
	else
		return (0);
}
