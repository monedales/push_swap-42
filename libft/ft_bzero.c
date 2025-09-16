/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:15:38 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/23 18:30:19 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Writes zero-valued bytes to a block of memory.
 *
 * This function sets the first 'num' bytes of the memory area
 * pointed to by 'str' to zero (value '\0').
 *
 * @param str Pointer to the memory area to be zeroed.
 * @param num The number of bytes to set to zero.
 * @return None.
 */
void	ft_bzero(void *str, size_t num)
{
	unsigned char	*ptr;
	size_t			count;

	ptr = (unsigned char *)str;
	count = 0;
	while (count < num)
	{
		ptr[count] = '\0';
		count++;
	}
}
