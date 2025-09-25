/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 20:07:40 by mona              #+#    #+#             */
/*   Updated: 2025/09/24 20:11:09 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *str, char delimit)
{
	size_t	word;
	size_t	count;

	word = 0;
	count = 0;
	while (str[count])
	{
		while (str[count] == delimit)
			count++;
		if (str[count])
		{
			word++;
			while (str[count] != delimit && str[count])
				count++;
		}
	}
	return (word);
}