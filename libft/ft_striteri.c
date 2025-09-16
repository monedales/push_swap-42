/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:47:27 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/25 13:51:17 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Apply a function to each character of a string.
 *
 * Applies the function ’f’ to each character of the string passed as argument,
 * passing its index as the first argument. Each character is passed by address
 * to ’f’ so it can be modified if necessary.
 *
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 * @return None.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	count;

	count = 0;
	if (!s || !f)
		return ;
	while (s[count])
	{
		f(count, &s[count]);
		count++;
	}
}
// // Função que transforma o caractere em maiúsculo
// void	to_upper_in_place(unsigned int i, char *c)
// {
// 	(void)i; // ignoramos o índice aqui
// 	if (*c >= 'a' && *c <= 'z')
// 		*c = *c - 32;
// }
// int	main(void)
// {
// 	char	str[] = "hello, 42!";
// 	printf("Antes: %s\n", str);
// 	ft_striteri(NULL, to_upper_in_place);
// 	printf("Depois: %s\n", str);
// 	return (0);
// }