/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:24:16 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/30 15:45:05 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_arr(char **arr, size_t limit)
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

static size_t	count_words(const char *str, char delimit)
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

static char	*extract_word(const char *str, char chr, size_t *current)
{
	size_t	start;
	size_t	end;

	start = *current;
	while (str[start] == chr)
		start++;
	if (!str[start])
		return (NULL);
	end = start;
	while (str[end] && str[end] != chr)
		end++;
	*current = end;
	return (ft_substr(str, start, end - start));
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	len;
	size_t	count_w;
	size_t	start;

	len = count_words(s, c);
	arr = ft_calloc(len + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	count_w = 0;
	start = 0;
	while (count_w < len)
	{
		arr[count_w] = extract_word(s, c, &start);
		if (!arr[count_w])
		{
			free_arr(arr, count_w);
			return (NULL);
		}
		count_w++;
	}
	return (arr);
}

// int	main(void)
// {
// 	// char	*str = "  hello  world  split ";
// 	char	**result;
// 	int		i;

// 	// printf("words: %ld\n", count_words(str, ' '));
// 	result = ft_split("", ' ');
// 	if (!result)
// 	{
// 		printf("Erro ao dividir a string.\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("Palavra %d: \"%s\"\n", i, result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }