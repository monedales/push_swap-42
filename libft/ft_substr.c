/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:56:05 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/25 18:55:02 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Extract a substring from a string.
 *
 * Allocates memory (using malloc(3)) and returns a substring from the string 
 * ’s’. The substring starts at index ’start’ and has a maximum length of ’len’.
 *
 * @param s The original string from which to create the substring.
 * @param start The starting index of the substring within ’s’.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			total_len;

	total_len = ft_strlen(s);
	if (start >= total_len)
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	sub = ft_calloc((len + 1), sizeof(char));
	if (!sub)
		return (NULL);
	ft_memcpy(sub, &s[start], len);
	return (sub);
}
// int main(void)
// {
// 	char *s2 = "0123456";
// 	char *subs = ft_substr(s2, 2, 11);

// 	printf("seila: %s\n TOTAL len: %ld\n", s2, ft_strlen(s2));
// 	printf("sub: %s\n", subs);
// 	free(subs);
// 	return (0);
// }