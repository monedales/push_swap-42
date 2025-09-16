/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:59:51 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/25 22:36:53 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Trims character 'set' from string 's1'.
 *
 * Allocates memory (using malloc(3)) and returns a copy of ’s1’ with characters
 * from ’set’ removed from the beginning and the end.
 *
 * @param s1 The string to be trimmed.
 * @param set The string containing the set of characters to be removed.
 * @return The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char			*tr_str;
	unsigned int	start;
	size_t			end;
	size_t			len;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[start]))
		start++;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	len = end - start + 1;
	tr_str = ft_substr(s1, start, len);
	if (!tr_str)
		return (NULL);
	return (tr_str);
}
// int main(void)
// {
// 	char *result;

// 	// Caso 1: Espaços no começo e fim
// 	result = ft_strtrim("   Hello, World!   ", " ");
// 	printf("Caso 1: '%s'\n", result);
// 	free(result);

// 	// Caso 2: Vários caracteres no set
// 	result = ft_strtrim("xxxyTrim Testzzz", "xyz");
// 	printf("Caso 2: '%s'\n", result);
// 	free(result);

// 	// Caso 3: Nada pra remover
// 	result = ft_strtrim("Nothing to trim", "123");
// 	printf("Caso 3: '%s'\n", result);
// 	free(result);

// 	// Caso 4: Tudo removido
// 	result = ft_strtrim("aaa", "a");
// 	printf("Caso 4: '%s'\n", result);
// 	free(result);

// 	// Caso 5: String vazia
// 	result = ft_strtrim("", "abc");
// 	printf("Caso 5: '%s'\n", result);
// 	free(result);

// 	// Caso 6: Set vazio
// 	result = ft_strtrim("Only spaces?", "");
// 	printf("Caso 6: '%s'\n", result);
// 	free(result);

// 	// Caso 7: Ambos vazios
// 	result = ft_strtrim("", "");
// 	printf("Caso 7: '%s'\n", result);
// 	free(result);
// 	return (0);
// }