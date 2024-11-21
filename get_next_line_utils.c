/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 05:33:05 by anktiri           #+#    #+#             */
/*   Updated: 2024/11/21 10:41:37 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	a;

	a = 0;
	if (!s)
		return (NULL);
	while (s[a])
	{
		if (s[a] == (char)c)
			return ((char *)&s[a]);
		a++;
	}
	if (s[a] == (char)c)
		return ((char *)&s[a]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	a;

	a = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (a < (count * size))
	{
		ptr[a] = '\0';
		a++;
	}
	return (ptr);
}

char	*strjoin(char *s1, char *s2)
{
	char	*str;
	int		a;
	int		b;

	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc(((ft_strlen(s1) + ft_strlen(s2)) + 1), 1);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	a = 0;
	while (s1[a])
	{
		str[a] = s1[a];
		a++;
	}
	b = 0;
	while (s2[b])
		str[a++] = s2[b++];
	free(s1);
	return (str);
}

char	*leftover(char *buffer)
{
	char	*nbuffer;
	int		a;
	int		n;

	if (!buffer || buffer[0] == '\0')
	{
		free (buffer);
		return (NULL);
	}
	n = 0;
	while (buffer[n] && buffer[n] != '\n')
		n++;
	if (!buffer[n])
	{
		free (buffer);
		return (NULL);
	}
	nbuffer = ft_calloc((ft_strlen(buffer) - n) + 1, 1);
	if (!nbuffer)
	{
		free(buffer);
		return (NULL);
	}
	a = 0;
	while (buffer[n])
		nbuffer[a++] = buffer[n++];
	free (buffer);
	return (nbuffer);
}
