/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:42:06 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/16 14:12:05 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of digits needed to represent an integer, 
 * including sign.
 *
 * Handles negative numbers by counting the '-' sign.
 *
 * @param n The integer number to count digits for.
 * @return Number of characters needed to represent 'n' as a string.
 */
static int	ft_lendigits(int n)
{
	size_t	count;
	int		is_negative;
	long	num;

	num = n;
	is_negative = 0;
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	count = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count + is_negative);
}

/**
 * @brief Counts the number of digits needed to represent an unsigned integer.
 *
 * @param n The unsigned integer number to count digits for.
 * @return Number of characters needed to represent 'n' as a string.
 */
static int	ft_lendigits_unsigned(unsigned int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

/**
 * @brief Prints an integer number to standard output.
 *
 * Uses ft_putnbr_fd to write the number and returns the 
 * number of characters printed.
 *
 * @param n The integer to print.
 * @return Number of characters printed.
 */
int	ft_putnbr(int n)
{
	long	num;

	num = n;
	ft_putnbr_fd(num, 1);
	return (ft_lendigits(n));
}

/**
 * @brief Prints an unsigned integer number to standard output.
 *
 * Recursively prints each digit of the number.
 *
 * @param n The unsigned integer to print.
 * @return Number of characters printed.
 */
int	ft_putnbr_unsigned(unsigned int n)
{
	int	div;
	int	digit;

	div = n / 10;
	digit = (n % 10) + 48;
	if (div > 0)
		ft_putnbr_unsigned(div);
	ft_putchar_fd(digit, 1);
	return (ft_lendigits_unsigned(n));
}
