/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:13:54 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/15 21:35:42 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief converts a lowercase alphabetic character to an uppercase.
 *
 * This function checks if the given character c is a lowercase 
 * alphabetic character (a-z) and converts it to the corresponding 
 * uppercase letter (A-Z). If c is not a lowercase letter, it is 
 * returned unchanged.
 *
 * @param chr The character to convert.
 * @return  The uppercase equivalent if c is lowercase, otherwise c unchanged.
 */
int	ft_toupper(int chr)
{
	if (chr >= 97 && chr <= 122)
		chr = chr - 32;
	return (chr);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int chr = '\n';
// 	printf("%c\n", c);
// 	printf("%c\n", ft_toupper(c));
// 	return (0);
// }