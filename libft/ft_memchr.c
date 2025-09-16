/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:40:00 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/16 20:18:25 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Scans a memory area for a specific byte.
 *
 * This function scans the first 'num' bytes of the memory area pointed 
 * to by 'src' for the first occurrence of the byte 'chr'. 
 * Both are interpreted as unsigned char.
 *
 * @param src Pointer to the memory area to be scanned.
 * @param chr The byte to search for (interpreted as unsigned char).
 * @param num The number of bytes to scan.
 * @return A pointer to the matching byte, or NULL if not found.
 */
void	*ft_memchr(const void *src, int chr, size_t num)
{
	unsigned char	*psrc;
	unsigned char	u_char;
	size_t			count;

	count = 0;
	psrc = (unsigned char *)src;
	u_char = (unsigned char)chr;
	while (count < num)
	{
		if (psrc[count] == u_char)
			return ((void *)&psrc[count]);
		count++;
	}
	return (NULL);
}
