/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:41:27 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/23 19:43:20 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Outputs a string to the specified file descriptor.
 *
 * @param str The string to output.
 * @param fd The file descriptor on which to write.
 * @return None.
 */
void	ft_putstr_fd(char *str, int fd)
{
	size_t	len;

	len = ft_strlen(str);
	write(fd, str, len);
}

// int	main(void)
// {
// 	ft_putstr_fd("cazzo", 1);
// 	return (0);
// }