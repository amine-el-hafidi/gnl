#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
int	main()
{
	int fd = open("file", O_RDONLY);
	char *line;
	int i = 0;
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
		i++;
	}
}
