/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:50:02 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/16 16:17:51 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Fills a block of memory with a specific value.
 *
 * This function sets the first 'num' bytes of the memory area 
 * pointed to by 'str' to the specified value 'c' (interpreted 
 * as an unsigned char).
 *
 * @param str Pointer to the memory area to fill.
 * @param chr The value to set (interpreted as unsigned char).
 * @param num The number of bytes to fill.
 * @return The original pointer 'str'.
 */
void	*ft_memset(void *str, int chr, size_t num)
{
	unsigned char	u_char;
	unsigned char	*ptr;
	size_t			count;

	count = 0;
	ptr = (unsigned char *)str;
	u_char = (unsigned char)chr;
	while (count < num)
	{
		ptr[count] = u_char;
		count++;
	}
	return (str);
}
