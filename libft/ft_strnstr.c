/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:03:03 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/22 19:31:39 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Identify a substring in a string.
 *
 * Searches for the first occurrence of the substring 'needle' within the
 * string 'haystack', limiting the search to at most 'len' characters.
 * The comparison is done char-by-char, stopping if 'needle' is
 * fully matched, if the end of 'haystack' is reached, or if 'len' is reached.
 *
 * @param haystack Pointer to a string source.
 * @param needle Pointer to a substring to be found in 'haystack'.
 * @param len number of characters to search the string 'haystack'.
 * @return returns the pointer to the first occurence of 'needle' in 'haystack';
 * If 'needle' is an empty string, returns 'haystack'.
 * If needle is not found within the size of len, returns NULL.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count_h;
	size_t	count_n;

	if (needle[0] == '\0')
		return ((char *)haystack);
	count_h = 0;
	while (count_h < len && haystack[count_h])
	{
		count_n = 0;
		while ((haystack[count_h + count_n] == needle[count_n])
			&& (count_h + count_n < len) && needle[count_n])
			count_n++;
		if (needle[count_n] == '\0')
			return ((char *)&haystack[count_h]);
		count_h++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <bsd/string.h>
// int	main(void)
// {
// 	char	base[] = "sorvete com yanana y mel";
// 	char	comparison[] = "y mel";
// 	char	*ptr;

// 	printf("String 'base':\n%s\n", base);
// 	printf("Substring 'comparison':\n%s\n", comparison);
// 	// ptr = strnstr(base, comparison, 35);
// 	ptr = ft_strnstr(base, comparison, 35);
// 	// printf("Substring inicia na posição %ld\n", ptr - base);
// 	printf("Substring inicia na posição %s\n", ptr);
// 	return (0);
// }

// {
// 	int	i;
// 	int	c;
// 	c = 0;
// 	while (str[c] != '\0')
// 	{
// 		i = i * 10 + (str[c] - '0');
// 		c++;
// 	}
// 	return (i);
// }
// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	if (argc == 4)
// 		printf("AQUI ESTA: %s", ft_strnstr(argv[1], argv[2], Atoi(argv[3])));
// 	else
// 		printf(":c");
// }