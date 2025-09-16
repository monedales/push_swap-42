/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:40:47 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/16 14:12:09 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Checks the format specifier and calls the appropriate print function.
 *
 * This function handles the supported conversion specifiers for ft_printf
 * and extracts the corresponding argument from the variable argument list.
 *
 * Supported specifiers: c, s, d, i, u, p, x, X, %
 *
 * @param specifier The format specifier character.
 * @param args The va_list containing the variable arguments.
 * @return Number of characters printed for the specifier.
 */
static int	check_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'p')
		return (ft_printptr(va_arg(args, unsigned long)));
	else if (specifier == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), specifier));
	else if (specifier == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), specifier));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

/**
 * @brief Mimics the standard printf function with limited specifiers.
 *
 * Parses the format string and prints characters and formatted arguments
 * according to the supported specifiers.
 *
 * @param format The format string.
 * @param ... Variable arguments corresponding to the format specifiers.
 * @return Total number of characters printed.
 */
int	ft_printf(const char *format, ...)
{
	size_t	printed_chars;
	va_list	args;
	int		index;

	va_start(args, format);
	index = 0;
	printed_chars = 0;
	while (format[index])
	{
		if (format[index] == '%' && format[index + 1])
		{
			printed_chars += check_specifier(format[index + 1], args);
			index++;
		}
		else
		{
			write(1, &format[index], 1);
			printed_chars++;
		}
		index++;
	}
	va_end(args);
	return (printed_chars);
}
