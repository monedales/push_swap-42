/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:17:27 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/18 14:39:38 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Copy a string with a limit on the destination buffer size.
 *
 * This function copies the string from 'src' to 'dest'. It copies at most
 * (size - 1) characters to ensure there is always space left for the
 * null-terminator '\0'. This way, if 'size' is greater than 0, the result
 * will always be a valid string.
 * For example, if 'size' is 10, the function copies at most 9 characters
 * and then adds '\0' at the end of 'dest'.
 *
 * The function returns the total length of the source string 'src', not
 * the number of characters copied. This allows you to check whether the
 * whole source string was copied or if it was too long for the buffer.
 *
 * @param dest Pointer to the destination string memory area.
 * @param src Pointer to the source string memory area to be copied.
 * @param size Size of the destination buffer.
 * @return The total lenght of the string source.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		count;

	count = 0;
	if (size > 0)
	{
		while (count < size - 1 && src[count])
		{
			dest[count] = src[count];
			count++;
		}
		dest[count] = '\0';
	}
	return (ft_strlen(src));
}
// #include <bsd/string.h>
// #include <stdio.h>
// int main(void)
// {
//     char dest1[20];
//     char dest2[20];
//     const char *src = "hello world";
//     size_t ret;
//     // Test 1: size > strlen(src)
//     ret = ft_strlcpy(dest1, src, sizeof(dest1));
//     printf("ft_strlcpy: dest = \"%s\", returned = %lu\n", dest1, ret);
//     // Compare with libc strlcpy
//     ret = strlcpy(dest2, src, sizeof(dest2));
//     printf("strlcpy   : dest = \"%s\", returned = %lu\n", dest2, ret);
//     // Test 2: size = 0
//     char dest3[20] = "unchanged";
//     ret = ft_strlcpy(dest3, src, 0);
//     printf("\nft_strlcpy with size 0: dest = \"%s\", 
// 	returned = %lu\n", dest3, ret);
// //     return 0;
// // }