/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:24:16 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/25 18:14:12 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Extracts a single word from a string starting at a given position.
 *
 * Skips leading delimiters, then extracts characters until the next delimiter
 * or end of string is found. Updates the current position pointer to the end
 * of the extracted word. This is a helper function for ft_split.
 *
 * @param str The source string to extract from.
 * @param chr The delimiter character to look for.
 * @param current Pointer to the current position in the string, updated after
 * extraction.
 * @return A newly allocated string containing the extracted word, or NULL if 
 * no word found.
 */
static char	*extract_word(const char *str, char chr, size_t *current)
{
	size_t	start;
	size_t	end;

	start = *current;
	while (str[start] == chr)
		start++;
	if (!str[start])
		return (NULL);
	end = start;
	while (str[end] && str[end] != chr)
		end++;
	*current = end;
	return (ft_substr(str, start, end - start));
}

/**
 * @brief Splits a string into an array of strings using a delimiter.
 *
 * Allocates and returns an array of strings obtained by splitting the input
 * string using the specified delimiter. Each word becomes a separate string
 * in the result array. The array is null-terminated. If memory allocation
 * fails at any point, all previously allocated memory is freed.
 *
 * @param s The string to split.
 * @param c The delimiter character used for splitting.
 * @return An array of strings representing the split result, or NULL on failure.
 */
char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	len;
	size_t	count_w;
	size_t	start;

	len = count_words(s, c);
	arr = ft_calloc(len + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	count_w = 0;
	start = 0;
	while (count_w < len)
	{
		arr[count_w] = extract_word(s, c, &start);
		if (!arr[count_w])
		{
			ft_free_arr(arr, count_w);
			return (NULL);
		}
		count_w++;
	}
	return (arr);
}

// int	main(void)
// {
// 	// char	*str = "  hello  world  split ";
// 	char	**result;
// 	int		i;

// 	// printf("words: %ld\n", count_words(str, ' '));
// 	result = ft_split("", ' ');
// 	if (!result)
// 	{
// 		printf("Erro ao dividir a string.\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("Palavra %d: \"%s\"\n", i, result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }