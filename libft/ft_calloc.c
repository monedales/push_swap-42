/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:02:51 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/31 13:09:47 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Memory allocation filled with zero-valued bytes.
 *
 *  This function allocates memory for an array of 'amount' elements, each of 
 * 'bytes_size' bytes, and sets all bytes in the allocated memory to zero.
 * 
 * It includes protection against overflow by checking whether the 
 * multiplication of 'amount' and 'bytes_size' would exceed the maximum 
 * value representable by size_t. If so, it returns NULL to prevent undefined 
 * behavior.
 *
 * @param amount Specifies the amount of items to allocate memory for.
 * @param bytes_size Specifies the size of each item measured in bytes.
 * @return On success, returns a pointer to the allocated memory setted to zero.
 * 	- If 'amount' or 'bytes_size' is 0, it returns a valid pointer that 
 * can be passed successfully to free().
 *  - If there's a chance of overflow by multiplicating 'amount' * 'bytes_size',
 * the return is NULL.
 */
void	*ft_calloc(size_t amount, size_t bytes_size)
{
	void	*ptr_arr;
	size_t	bytes_to_fill;
	size_t	size_max;

	size_max = (size_t)-1;
	if (amount == 0 || bytes_size == 0)
		return (malloc(1));
	if (amount > size_max / bytes_size)
		return (NULL);
	bytes_to_fill = amount * bytes_size;
	ptr_arr = malloc(bytes_to_fill);
	if (!ptr_arr)
		return (NULL);
	ft_bzero(ptr_arr, bytes_to_fill);
	return (ptr_arr);
}

// int main(void)
// {
// 	int *arr_lib = calloc(5, sizeof(int));
// 	int *arr_ft = ft_calloc(5, sizeof(int));
// 	printf("calloc oficial:\n");
// 	for (int i = 0; i < 5; i++)
// 		printf("%d ", arr_lib[i]);
// 	printf("\n");
// 	printf("ft_calloc:\n");
// 	for (int i = 0; i < 5; i++)
// 		printf("%d ", arr_ft[i]);
// 	printf("\n");
// 	free(arr_lib);
// 	free(arr_ft);
// 	return (0);
// 	return (0);
// }