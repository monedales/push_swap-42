/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:13:25 by maria-ol          #+#    #+#             */
/*   Updated: 2025/08/06 20:59:48 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Recursively prints the number 'n' in hexadecimal format.
 *
 * This function prints the hexadecimal representation of 'n' to standard output.
 * The case of the letters depends on the 'specifier' parameter:
 * - 'x' or 'p' uses lowercase letters (a-f).
 * - 'X' uses uppercase letters (A-F).
 *
 * @param n The number to print in hexadecimal.
 * @param specifier Character specifying the format ('x', 'X', or 'p').
 * @return Number of characters printed.
 */
int	ft_print_hex(unsigned long n, char specifier)
{
	unsigned long	quo;
	unsigned long	digit;
	size_t			len;
	char			chr;

	len = 0;
	quo = n / 16;
	if (n >= 16)
		len = len + ft_print_hex(quo, specifier);
	digit = n - (quo * 16);
	if (digit < 10)
		chr = '0' + digit;
	else if (digit >= 10 && (specifier == 'x' || specifier == 'p'))
		chr = 'a' + (digit - 10);
	else
		chr = 'A' + (digit - 10);
	len = len + write(1, &chr, 1);
	return (len);
}

/**
 * @brief Prints a pointer address in the standard format.
 *
 * If 'n' is 0, prints "(nil)".
 * Otherwise, prints the address prefixed with "0x" followed by the
 * hexadecimal representation of 'n' in lowercase.
 *
 * @param n The pointer value to print.
 * @return Number of characters printed.
 */
int	ft_printptr(unsigned long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = ft_putstr("(nil)");
	else
		len = ft_putstr("0x") + ft_print_hex(n, 'p');
	return (len);
}
