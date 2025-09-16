/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:03:01 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/16 21:22:15 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Compares two strings at a specified 'num' of bytes.
 *
 * This function compares the strings 's1' and 's2', interpreting them as 
 * arrays of unsigned char. The comparison is performed byte by byte up to 
 * 'num' bytes or until a difference is found.
 *
 * @param s1 Pointer to the first string to be compared.
 * @param s2 Pointer to the second string to be compared.
 * @param num Maximum number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero:
 * - Returns zero if the compared bytes are equal.
 * - Returns the difference between the first differing byte 
 * (s1[count] - s2[count]).
 * - If 'num' is zero, the return value is zero.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	size_t			count;

	count = 0;
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (count < num && (ps1[count] || ps2[count]))
	{
		if (ps1[count] != ps2[count])
			return (ps1[count] - ps2[count]);
		count++;
	}
	return (0);
}
