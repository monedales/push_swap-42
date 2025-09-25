/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:48:49 by mona              #+#    #+#             */
/*   Updated: 2025/09/25 11:40:21 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convert a string to a long integer
 *
 * This function converts the initial portion of the string pointed to by 'str'
 * to long. The beginning of 'str' may contain whitespace characters followed by
 * a single optional '+' or '-' sign. After a digit is found the conversion
 * continues until a non-digit character is encountered.
 *
 * @param str Pointer to a string containing a representation of a whole number.
 * @return An long value containing the converted 'str' or 0 on error.
 */

long ft_atol(const char *str)
{
	long	result;
	int		count;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[count]) == 1)
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -sign;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		result = result * 10 + (str[count] - '0');
		count++;
	}
	return (result * sign);
}

// int main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("ft_atol: %ld\n", ft_atol(argv[1]));
// 		printf("atol:    %ld\n", atol(argv[1]));
// 	}
// 	return (0);
// }