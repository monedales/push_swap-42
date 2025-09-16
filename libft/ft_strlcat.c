/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:47:24 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/18 16:58:02 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Concatenates strings with a limit into a buffer with size limit.
 *
 * This function concatenates the string 'src' to the end of 'dest' without 
 * exceeding 'dsize'. At most (dsize - strlen(dest) - 1) characters are 
 * copied from 'src', leaving space for the null-terminator '\0'.
 * If 'dsize' is 10, for example, it copies up to 9 characters total
 * (including the original 'dest') and ensures '\0' at the end.
 *
 * Returns the initial length of 'dest' plus the length of 'src'.
 * This allows detection of whether the result was truncated(if 
 * return >= dsize, the concatenation was incomplete).
 *
 * @param dest Pointer to the destination string to be concatenated.
 * @param src Pointer to the source string memory area to concatenate.
 * @param dsize Total size of the destination buffer.
 * @return The initial lenght of the string dest plus the leght of src.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	size_t	num_bytes;
	size_t	len_s;
	size_t	len_d;

	len_s = ft_strlen(src);
	len_d = ft_strlen(dest);
	if (len_d >= dsize)
		return (dsize + len_s);
	num_bytes = dsize - len_d - 1;
	if (num_bytes < len_s)
		ft_memcpy(dest + len_d, src, num_bytes);
	else
	{
		num_bytes = len_s;
		ft_memcpy(dest + len_d, src, num_bytes);
	}
	dest[len_d + num_bytes] = '\0';
	return (len_d + len_s);
}
