#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

int		check_n(char *s);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*read_line(int fd, char *saved);
char	*extract_line(char *saved);
char	*update_saved(char *saved);
char	*get_next_line(int fd);

#endif
