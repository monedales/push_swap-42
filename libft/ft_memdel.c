/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:15:59 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/16 14:16:23 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Safely deallocates memory and sets pointer to NULL.
 *
 * This function frees the memory pointed to by the pointer stored at 
 * 'address_ptr' and then sets that pointer to NULL to prevent dangling 
 * pointer issues. If either 'address_ptr' or the pointer it points to 
 * is NULL, the function does nothing.
 *
 * @param address_ptr Pointer to a pointer that will be freed and set to NULL.
 * @return None.
 */
void	ft_memdel(void **address_ptr)
{
	if (address_ptr && *address_ptr)
	{
		free(*address_ptr);
		*address_ptr = NULL;
	}
}
