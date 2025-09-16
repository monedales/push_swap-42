/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:54:33 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/23 19:43:53 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Outputs a string to the specified file descriptor.
 * 
 * Outputs the string ’str’ to the given file descriptor, 
 * followed by a newline.
 *
 * @param str The string to output.
 * @param fd The file descriptor on which to write.
 * @return None.
 */
void	ft_putendl_fd(char *str, int fd)
{
	size_t	len;

	len = ft_strlen(str);
	write(fd, str, len);
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	ft_putendl_fd("", 2);
// 	return (0);
// }