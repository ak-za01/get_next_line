# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, char c);
size_t	ft_strlen(const char *s);
void 	*ft_free(char *buffer);
char 	*ft_calloc(size_t size);
char	*join(char *s1, char *s2);

#endif