/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:18:42 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/24 19:32:40 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Copies memory area.
 *
 * This function copies a 'num' bytes of the memory area 
 * pointed to by 'src' to the memory area pointed to by 'dest'.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param num The number of bytes to copy.
 * @return The original pointer 'dest'.
 */
void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	size_t			count;

	count = 0;
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (count < num)
	{
		pdest[count] = psrc[count];
		count++;
	}
	return (dest);
}
