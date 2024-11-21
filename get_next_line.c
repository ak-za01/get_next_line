/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:42:04 by anktiri           #+#    #+#             */
/*   Updated: 2024/11/21 10:45:56 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line(char *buffer)
{
	char	*line;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (!buffer || buffer[0] == 0)
		return (NULL);
	while (buffer[b] && buffer[b] != '\n')
		b++;
	line = ft_calloc(b + 2, 1);
	if (!line)
		return (NULL);
	while (buffer[a] && a < b)
	{
		line[a] = buffer[a];
		a++;
	}
	return (line);
}

char	*convert(char *buffer, char *line)
{
	char	*new;

	new = strjoin(buffer, line);
	free(buffer);
	return (new);
}

char	*read_line(int fd, char *buffer)
{
	ssize_t	bytes_in_buffer;
	char	*line;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	line = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	bytes_in_buffer = 1;
	while (bytes_in_buffer > 0)
	{
		bytes_in_buffer = read(fd, line, BUFFER_SIZE);
		if (bytes_in_buffer == -1)
		{
			free(line);
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		buffer = strjoin(buffer, line);
		if (buffer || ft_strchr(buffer, '\n'))
			break ;
	}
	free(line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = new_line(buffer);
	if (!line)
		return (NULL);
	buffer = leftover(buffer);
	return (line);
}
