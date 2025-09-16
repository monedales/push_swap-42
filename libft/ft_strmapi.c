/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:46:22 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/24 20:10:03 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Apply a function to each character of a string
 *
 * Applies the function f to each character of the string s, passing its index 
 * as the first argument and the character itself as the second. A new string 
 * is created (using malloc(3)) to store the results from the successive 
 * applications of f.
 *
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 * @return Returns the string created from the successive applications
 * of ’f’.
 * - Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	count;
	char			*result;

	count = 0;
	len = ft_strlen(s);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (count < len)
	{
		result[count] = f(count, s[count]);
		count++;
	}
	result[count] = '\0';
	return (result);
}

// char	touppereven(unsigned int i, char c)
// {
// 	if (i % 2 && c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }
// char	mask_vowels(unsigned int i, char c)
// {
// 	(void)i;
// 	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
// 		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
// 		return ('*');
// 	return (c);
// }

// int	main(void)
// {
// 	char *str = "my lib, my rules.";
// 	char *result = ft_strmapi(str, touppereven);
// 	char *result2 = ft_strmapi(str, mask_vowels);

// 	printf("Original: %s\n", str);
// 	printf("Result:   %s\n", result);
// 	printf("Result2:   %s\n", result2);
// 	free(result);

// 	return (0);
// }
