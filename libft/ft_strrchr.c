/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:32:36 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/18 11:14:59 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Find last occurrence of a character in a string.
 *
 * Similar to ft_strchr, this function searches for the last occurrence of 
 * the character 'chr'(converted  * to a char) in the string pointed to by
 * 'str'. The null terminator '\0' is considered part of the string, so if 
 * 'chr' is '\0', the function returns a pointer to the null terminator.
 *
 * @param str The string to search.
 * @param chr The character to find, passed as an int but interpreted as a char.
 * @return A pointer to the last occurrence of the character in the string,
 * or NULL if the character is not found.
 */
char	*ft_strrchr(const char *str, int chr)
{
	char	uchr;
	int		count;

	count = ft_strlen(str);
	uchr = (char)chr;
	while (count >= 0)
	{
		if (str[count] == uchr)
			return ((char *)&str[count]);
		count--;
	}
	if (uchr == '\0')
		return ((char *)&str[count]);
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char str[] = "bonjour";
// 	printf("FAKE: %s\n", ft_strrchr(str + 2, 'b'));
// 	printf("ORIGINAL: %s\n", strrchr(str + 2, 'b'));
// 	printf("FAKE: %s\n", ft_strrchr(str, 's'));
// 	printf("ORIGINAL: %s\n", strrchr(str, 's'));
// 	printf("FAKE: %s\n", ft_strrchr(str, 'b'));
// 	printf("ORIGINAL: %s\n", strrchr(str, 'b'));
// 	printf("FAKE: %s\n", ft_strrchr(str, '\0'));
// 	printf("ORIGINAL: %s\n", strrchr(str, '\0'));
// 	printf("FAKE PTR: %p\n", ft_strrchr(str, 'b'));
// 	printf("ORIGINAL PTR: %p\n", strrchr(str, 'b'));
// 	return (0);
// }