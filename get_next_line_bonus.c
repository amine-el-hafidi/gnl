
#include "get_next_line_bonus.h"

char	*read_line(int fd, char *saved)
{
	int		read_bytes;
	char	*buffer;
	char	*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(saved), NULL);
	read_bytes = 0;
	while (!check_n(saved))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0)
			break ;
		if (read_bytes == -1)
			return (free(buffer), free(saved), NULL);
		buffer[read_bytes] = '\0';
		tmp = ft_strjoin(saved, buffer);
		if (!tmp)
			return (free(buffer), free(saved), NULL);
		if (saved)
			free(saved);
		saved = tmp;
	}
	return (free(buffer), saved);
}

char	*extract_line(char *saved)
{
	int		i;
	char	*line;

	if (!saved || !saved[0])
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] && saved[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (free(saved), saved = NULL, NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] && saved[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_saved(char *saved)
{
	int		i;
	int		j;
	char	*buffer;

	if (!saved || !saved[0])
		return (free(saved), saved = NULL, NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] && saved[i] == '\n')
		i++;
	buffer = malloc(ft_strlen(saved) - i + 1);
	if (!buffer)
		return (free(saved), saved = NULL, NULL);
	j = 0;
	while (saved[i + j])
	{
		buffer[j] = saved[i + j];
		j++;
	}
	buffer[j] = '\0';
	free(saved);
	saved = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*saved[1024];
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (free(saved[fd]), saved = NULL, NULL);
	saved[fd] = read_line(fd, saved[fd]);
	if (!saved[fd])
		return (NULL);
	line = extract_line(saved[fd]);
	if (!line)
		return (free(saved[fd]), saved[fd] = NULL, NULL);
	saved[fd] = update_saved(saved[fd]);
	return (line);
}
