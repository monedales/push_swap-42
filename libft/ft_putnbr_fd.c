/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:02:00 by maria-ol          #+#    #+#             */
/*   Updated: 2025/08/06 13:31:37 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Prints an integer to the specified file descriptor.
 *
 * Outputs the integer ’n’ to the specified file descriptor.
 *
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 * @return None.
 */
void	ft_putnbr_fd(int n, int fd)
{
	int		div;
	int		digit;
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	div = (num / 10);
	digit = (num % 10) + 48;
	if (div > 0)
		ft_putnbr_fd(div, fd);
	ft_putchar_fd(digit, fd);
}
// int	main(void)
// {
// 	ft_putnbr_fd(-120, 2);
// 	ft_putnbr_fd(2103, 2);
// 	return (0);
// }