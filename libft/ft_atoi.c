/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:33:31 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/23 14:39:59 by maria-ol         ###   ########.fr       */
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
static int	ft_isspace(int chr)
{
	if ((chr >= 9 && chr <= 13) || chr == 32)
		return (1);
	return (0);
}
/**
 * @brief Convert a string to a integer
 *
 * This function converts the initial portion of the string pointed to by 'str' 
 * to int. The beggining of 'str' may contain whitespace characters followed by
 * a single optional '+' or '-' sign. After a digit is found the conversion 
 * continues until a non-digit character is encountered.
 * 
 *
 * @param str Pointer to a string containing a representation of a whole number.
 * @return An int value containing the converted 'str' or 0 on error.
 */

int	ft_atoi(const char *str)
{
	int	count;
	int	result;
	int	sign;

	count = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[count]) == 1)
		count++ ;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -sign;
		count++;
	}
	while (str[count] && str[count] >= 48 && str[count] <= 57)
	{
		result = result * 10 + (str[count] - 48);
		count++;
	}
	return (result * sign);
}
// int main(void)
// {
// 	char *str = "        -12\n55aaa534";
// 	printf("fake: %d\n", ft_atoi(str));
// 	printf("origin: %d", atoi(str));
// 	return (0);
// }