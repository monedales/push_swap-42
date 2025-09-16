/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:20:03 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/17 13:51:17 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Compares two memory areas byte by byte.
 *
 * This function compares the first 'num' bytes of the memory areas
 * pointed to by 's1' and 's2'. Both are interpreted as arrays of 
 * unsigned char. The comparison is done byte by byte.
 *
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param num The number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero:
 * - Returns zero if the memory areas are equal.
 * - Returns the difference between the first differing bytes 
 * (s1[count] - s2[count]).
 * - If 'num' is zero, the return value is zero.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t num)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	size_t			count;

	count = 0;
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (count < num)
	{
		if (ps1[count] != ps2[count])
			return (ps1[count] - ps2[count]);
		count++;
	}
	return (0);
}
