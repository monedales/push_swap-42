/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:13:50 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/15 21:35:42 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief converts an uppercase alphabetic character to a lowercase.
 *
 * This function checks if the given character c is an uppercase 
 * alphabetic character (A-Z) and converts it to the corresponding 
 * lowercase letter (a-z). If c is not an uppercase letter, it is 
 * returned unchanged.
 *
 * @param chr The character to convert.
 * @return  The lowercase equivalent if c is uppercase, otherwise c unchanged.
 */
int	ft_tolower(int chr)
{
	if (chr >= 65 && chr <= 90)
		chr = chr + 32;
	return (chr);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int chr = 'A';
// 	printf("%c\n", c);
// 	printf("%c\n", ft_tolower(c));
// 	return (0);
// }