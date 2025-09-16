/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:30:33 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/29 16:21:52 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(long n);
static void		recursive_digits(char *str, long nb, int index);

/**
 * @brief Convert an int to a string
 *
 * Allocates memory (using malloc(3)) and returns a string representing the 
 * integer received as an argument. Negative numbers must be handled.
 *
 * @param n The integer to convert.
 * @return The string representing the integer. NULL if the allocation fails.
 */
char	*ft_itoa(int n)
{
	char	*new_str;
	size_t	len;
	long	num;
	int		is_negative;

	num = n;
	is_negative = 0;
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	len = count_digits(num) + is_negative;
	new_str = ft_calloc(len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	if (is_negative)
	{
		new_str[0] = '-';
		recursive_digits(new_str, num, len - 1);
	}
	else
		recursive_digits(new_str, num, len - 1);
	return (new_str);
}

static void	recursive_digits(char *str, long nb, int index)
{
	int	div;
	int	digit;

	div = (nb / 10);
	digit = (nb % 10);
	if (nb < 10)
		str[index] = nb + 48;
	else
	{
		recursive_digits(str, div, index - 1);
		str[index] = digit + 48;
	}
}

static size_t	count_digits(long n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
// int	main(void)
// {
// 	char	*str;

// 	str = ft_itoa(0);
// 	printf("itoa(0)         = %s\n", str);
// 	free(str);

// 	str = ft_itoa(42);
// 	printf("itoa(42)        = %s\n", str);
// 	free(str);

// 	str = ft_itoa(-42);
// 	printf("itoa(-42)       = %s\n", str);
// 	free(str);

// 	str = ft_itoa(123456789);
// 	printf("itoa(123456789) = %s\n", str);
// 	free(str);

// 	str = ft_itoa(-123456789);
// 	printf("itoa(-123456789)= %s\n", str);
// 	free(str);

// 	str = ft_itoa(INT_MAX);
// 	printf("itoa(INT_MAX)   = %s\n", str);
// 	free(str);

// 	str = ft_itoa(INT_MIN);
// 	printf("itoa(INT_MIN)   = %s\n", str);
// 	free(str);

// 	return (0);
// }