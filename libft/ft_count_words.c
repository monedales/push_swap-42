/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 20:07:40 by mona              #+#    #+#             */
/*   Updated: 2025/09/25 12:39:50 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Counts the number of words in a string separated by a delimiter.
 *
 * Traverses the string and counts words by identifying sequences of characters
 * that are not the delimiter. Multiple consecutive delimiters are treated as
 * a single separator. This function is commonly used to determine array size
 * before splitting a string.
 *
 * @param str The string to count words in.
 * @param delimit The character used as a word delimiter.
 * @return The number of words found in the string.
 */
size_t	ft_count_words(const char *str, char delimit)
{
	size_t	word;
	size_t	count;

	word = 0;
	count = 0;
	while (str[count])
	{
		while (str[count] == delimit)
			count++;
		if (str[count])
		{
			word++;
			while (str[count] != delimit && str[count])
				count++;
		}
	}
	return (word);
}