/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:05:39 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/22 14:08:32 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Duplicates 'str' string by allocating new memory dynamically.
 *
 * This function duplicates the string 'str' while using malloc function 
 * to allocate memory for the new string. The new string will contain the same 
 * characters as 'str' followed by a null-terminator '\0'.  
 *
 * @param str Pointer to the source string to be duplicated.
 * @return Returns a pointer to the duplicated string or NULL if is not
 * enough memory available.
 */
char	*ft_strdup(const char *str)
{
	char	*new_str;
	size_t	count;
	size_t	len;

	len = ft_strlen(str) + 1;
	new_str = malloc(len * sizeof(char));
	if (!new_str)
		return (NULL);
	count = 0;
	while (str[count])
	{
		new_str[count] = str[count];
		count++;
	}
	new_str[count] = '\0';
	return (new_str);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char	*origin = "hello hello hello";
// 	char	*doppelganger = ft_strdup(origin);

// 	if (doppelganger != NULL)
// 	{
// 		printf("Origin: %s\n", origin);
// 		printf("Doppelganger: %s\n", doppelganger);
// 	}
// 	else
// 	{
// 		printf("Fail!\n");
// 	}
// 	free(doppelganger);
// 	return (0);
// }