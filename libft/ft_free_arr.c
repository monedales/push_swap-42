/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:22:08 by mona              #+#    #+#             */
/*   Updated: 2025/09/25 12:39:21 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Frees a dynamically allocated string array with a specified limit.
 *
 * Iterates through the array up to the specified limit, freeing each string
 * individually, then frees the array itself. This function is useful when
 * you know exactly how many elements to free, especially in error handling
 * scenarios where the array might be partially filled.
 *
 * @param arr The string array to be freed.
 * @param limit The number of elements to free (not including the array itself).
 */
void	ft_free_arr(char **arr, size_t limit)
{
	size_t	i;

	i = 0;
	while (i < limit)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}