/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:38:52 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/24 19:34:34 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Copies memory area without overlaping.
 *
 * This function copies a 'num' bytes of the memory area 
 * pointed to by 'src' to the memory area pointed to by 'dest'.
 * It handles overlapping memory regions by copying backwards 
 * when necessary.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param num The number of bytes to copy.
 * @return The original pointer 'dest'.
 */
void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	size_t			count;

	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (psrc < pdest)
	{
		count = num;
		while (count > 0)
		{
			count--;
			pdest[count] = psrc[count];
		}
	}
	else
		return (ft_memcpy(dest, src, num));
	return (dest);
}
