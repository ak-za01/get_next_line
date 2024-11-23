#include "get_next_line.h"

char *read_line(int fd, char *buffer)
{
	ssize_t	bytes_in_buffer;
	char	*line;

	if (!buffer)
		buffer = ft_calloc(1);
	line = ft_calloc(BUFFER_SIZE + 1);
	if (!line)
		return(ft_free(buffer));
	while (1)
	{
		bytes_in_buffer = read(fd, line, BUFFER_SIZE);
		if (bytes_in_buffer == -1)
			return(ft_free(line), ft_free(buffer));
		buffer = join(buffer, line);
		if (!buffer)
			return(ft_free(line));
		if (ft_strchr(line, '\n'));
			break ;
	}
	return(ft_free(line), buffer);
}

char	*new_line(char *buffer)
{
	char	*str;
	int		a;
	int		b;

	b = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[b] && buffer[b] != '\n')
		b++;
	if (buffer[b] == '\n')
		b++;
	str = ft_calloc(b + 1);
	if (!str)
		return (NULL);
	a = 0;
	while (buffer[a] && a < b)
	{
		str[a] = buffer[a];
		a++;
	}
	return ((str[a] = '\n'), str);
}

char	*chyata(char *buffer)
{
	char	*new_buffer;
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (buffer[b] && buffer[b] != '\n')
		b++;
	if (!buffer[b])
		return (ft_free(buffer));
	b++;
	new_buffer = ft_calloc(ft_strlen(buffer) - b + 1);
	if (!new_buffer)
		return (ft_free(buffer));
	while (buffer[b])
		new_buffer[a++] = buffer[b++];
	return (ft_free(buffer), new_buffer);
}

char *get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return(ft_free(buffer));
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (ft_free(buffer));
	line = new_line(buffer);
	if (!line)
		return (ft_free(buffer));
	buffer = chyata(buffer);
	return (line);
}
