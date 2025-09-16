/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:28:23 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/23 19:43:29 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Outputs a single character to the specified file descriptor.
 *
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 * @return None.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'c';
// 	ft_putchar_fd(c, 1);
// 	return (0);
// }