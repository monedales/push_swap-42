/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:36:11 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/16 14:21:54 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Reads from file descriptor and concatenates data to existing scraps.
 *
 * Continuously reads data from the file descriptor in chunks of BUFFER_SIZE
 * until a newline character is found or end of file is reached. Each read
 * chunk is concatenated to the existing 'scraps' string. The function handles
 * memory management by freeing the old 'scraps' after each concatenation.
 *
 * @param scraps The existing string to which new data will be concatenated.
 * @param buffer Temporary buffer used for reading data from the file descriptor.
 * @param fd The file descriptor to read from.
 * @return The updated string containing all concatenated data, or NULL on error.
 */
static char	*read_and_concat_to_scraps(char *scraps, char *buffer, int fd)
{
	char		*temp;
	ssize_t		bytes_read;

	bytes_read = 1;
	while (!(ft_strchr(scraps, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_memdel((void **)&scraps);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(scraps, buffer);
		if (!temp)
			return (NULL);
		ft_memdel((void **)&scraps);
		scraps = temp;
	}
	return (scraps);
}

/**
 * @brief Extracts a single line from the scraps string.
 *
 * Searches for the first newline character in 'scraps' and creates a substring
 * from the beginning up to and including the newline. If no newline is found,
 * the entire 'scraps' string is duplicated. This function is used to extract
 * the current line that should be returned by get_next_line.
 *
 * @param scraps The string containing buffered data from file reads.
 * @return A new string containing one line (with newline if present), 
 *         or NULL if allocation fails.
 */
static char	*extract_line(char *scraps)
{
	char	*line;
	char	*new_line;
	size_t	len;

	line = ft_strchr(scraps, '\n');
	if (line)
	{
		len = (line - scraps) + 1;
		new_line = ft_substr(scraps, 0, len);
	}
	else
		new_line = ft_strdup(scraps);
	return (new_line);
}

/**
 * @brief Extracts remaining data after the current line.
 *
 * After extracting a line, this function creates a new string containing
 * all data that comes after the first newline character in 'scraps'. 
 * The original 'scraps' memory is freed. If no newline is found, it means
 * all data was consumed and NULL is returned.
 *
 * @param scraps The string containing buffered data.
 * @return A new string with leftover data for subsequent calls, 
 *         or NULL if no data remains or allocation fails.
 */
static char	*extract_leftovers(char *scraps)
{
	char	*leftovers;
	char	*pos_new_line;
	size_t	i_start;

	pos_new_line = ft_strchr(scraps, '\n');
	if (!pos_new_line)
	{
		ft_memdel((void **)&scraps);
		return (NULL);
	}
	else
	{
		i_start = (pos_new_line - scraps) + 1;
		leftovers = ft_substr(scraps, i_start,
				ft_strlen(scraps) - i_start);
		ft_memdel((void **)&scraps);
	}
	return (leftovers);
}

/**
 * @brief Reads and returns the next line from a file descriptor.
 *
 * This function reads from a file descriptor one line at a time, where a line
 * is defined as a sequence of characters ending with '\n' or EOF. It uses a
 * static variable to maintain state between calls, allowing it to handle files
 * larger than the buffer size. Memory is automatically managed and cleaned up.
 *
 * @param fd The file descriptor to read from.
 * @return A string containing the next line (including '\n' if present), 
 *         or NULL when EOF is reached or an error occurs.
 */
char	*get_next_line(int fd)
{
	static char	*scraps = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (scraps)
			ft_memdel((void **)&scraps);
		return (NULL);
	}
	if (!scraps)
		scraps = ft_strdup("");
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	scraps = read_and_concat_to_scraps(scraps, buffer, fd);
	ft_memdel((void **)&buffer);
	if (!scraps || scraps[0] == '\0')
	{
		ft_memdel((void **)&scraps);
		return (NULL);
	}
	line = extract_line(scraps);
	scraps = extract_leftovers(scraps);
	return (line);
}
