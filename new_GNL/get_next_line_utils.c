#include "get_next_line.h"

char	*ft_strchr(const char *s, char c)
{
	int	a;

	a = 0;
	if (!s)
		return (NULL);
	while (s[a])
	{
		if (s[a] == c)
			return ((char *)&s[a]);
		a++;
	}
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

void	*ft_free(char *buffer)
{
	free(buffer);
	buffer = NULL;
	return (NULL);
}

char	*ft_calloc(size_t size)
{
	char	*p;
	size_t	a;

	a = 0;
	p = malloc(size);
	if (!p)
		return (NULL);
	while (a < size)
		p[a++] = '\0';
	return (p);
}

char	*join(char *s1, char *s2)
{
	char	*str;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return (ft_free(s1));
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (ft_free(s1));
	while (s1[a])
		str[b++] = s1[a++];
	a = 0;
	while (s2[a])
		str[b++] = s2[a];
	return (ft_free(s1), str);
}
