/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:44:06 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/17 18:37:05 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Find first occurrence of a character in a string.
 *
 * The function searches for the first occurrence of the character 
 * 'chr'(converted  * to a char) in the string pointed to by 'str'. 
 * The null terminator '\0' is considered part of the string, so if 
 * 'chr' is '\0', the function returns a pointer to the null terminator.
 *
 * @param str The string to search.
 * @param chr The character to find, passed as an int but interpreted as a char.
 * @return A pointer to the first occurrence of the character in the string,
 * or NULL if the character is not found.
 */
char	*ft_strchr(const char *str, int chr)
{
	char	uchr;
	size_t	count;

	count = 0;
	uchr = (char)chr;
	while (str[count])
	{
		if (str[count] == uchr)
			return ((char *)&str[count]);
		count++;
	}
	if (uchr == '\0')
		return ((char *)&str[count]);
	return (NULL);
}
