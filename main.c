#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>


// int main()
// {
// 	char	**file;
// 	char	*line;
// 	char	*newtmp;
// 	char	*target;
// 	char	*change;
// 	char	*tmp;
// 	int		a;
// 	int		b;
// 	int		i;
// 	int		j;
// 	int		fd;

// 	a = 0;
// 	target = "anktiri";
// 	change = "Hello World";
// 	fd = open("test.txt", O_RDWR | O_CREAT, 0777);

// 	while ((line = get_next_line(fd)))
// 	{
// 		// ft_upper(line, strlen(line));
// 		tmp = strstr(line, target);
// 		if (tmp)
// 		{
// 			i = -1;
// 			if (strlen(change) <= strlen(target))
// 			{
// 				while (++i < strlen(change))
// 					tmp[i] = change[i];
// 				while (i < strlen(target))
// 				{
// 					tmp[i] = ' ';
// 					i++;
// 				}
// 				printf("%s", line);
// 				file[a] = line;
// 			}
// 			else
// 			{
// 				i = -1;
// 				b = 0;
// 				newtmp = ft_calloc(strlen(line) + strlen(change) - strlen(target) + 1);
// 				while (++i < strlen(line) - strlen(tmp))
// 					newtmp[i] = line[i];
// 				j = i + strlen(target);
// 				while (change[b])
// 					newtmp[i++] = change[b++];
// 				while (line[j])
// 					newtmp[i++] = line[j++];
// 				file[a] = newtmp;
// 			}
// 			// ft_upper(strstr(line, target), strlen(target));
// 		}
// 		else
// 			file[a] = line;
// 		a++;
// 	}
// 	file[a] = 0;
// 	close (fd);

// 	fd = open("test.txt", O_TRUNC | O_RDWR, 0777);
// 	for (int i = 0; file[i]; i++)
// 		write(fd, file[i], strlen(file[i]));
// }

void	ft_upper(char *str, int len)
{
	int	a = 0;
	while (str[a] && a < len)
	{
		if (str[a] >= 'a' && str[a] <= 'z')
			str[a] -= 32;
		a++;
	}
	// return (str);
}

int main()
{
	char	**file;
	char	*line;
	char	*target;
	char	*tmp;
	int		fd;
	int		a;

	a = 0;
	target = "root123";
	fd = open("test.txt", O_RDWR | O_CREAT, 0777);
	while ((line = get_next_line(fd)))
	{
		// if (a == 3)
		// 	ft_upper(line, strlen(line));
		if ((tmp = strstr(line, target)))
			ft_upper(tmp, strlen(target));
		file[a] = line;
		a++;
	}
	file[a] = 0;
	close (fd);

	fd = open("test.txt", O_TRUNC | O_RDWR, 0777);
	for (int i = 0; file[i]; i++)
		write(fd, file[i], strlen(file[i]));
}
