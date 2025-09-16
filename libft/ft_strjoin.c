/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:56:02 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/25 18:23:52 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Concatenate two string into a new one.
 *
 * Allocates memory (using malloc(3)) and returns a new string, 
 * which is the result of concatenating ’s1’ and ’s2’.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*new_str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	new_str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, len_s1 + 1);
	ft_strlcat(new_str, s2, len_s1 + len_s2 + 1);
	return (new_str);
}
// int	main(void)
// {
// 	char *s1 = "oi gata, ";
// 	char *s2 = "quer tc?";
// 	char *new = ft_strjoin(s1, s2);

// 	printf("frase 1: %s\n len 1: %ld\n", s1, ft_strlen(s1));
// 	printf("frase 2: %s\n len 2: %ld\n", s2, ft_strlen(s2));
// 	printf("after join: %s", new);
// 	free(new);
// 	return (0);
// }