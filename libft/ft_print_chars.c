/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:01:23 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/16 14:11:55 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Writes the character 'c' to standard output.
 *
 * @param c The character to write.
 * @return Returns 1 on success.
 */
int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

/**
 * @brief Writes the string 'str' to standard output.
 *
 * If 'str' is NULL, writes "(null)" instead.
 *
 * @param str Pointer to the string to write.
 * @return Number of characters written.
 */
int	ft_putstr(char *str)
{
	size_t	len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}
