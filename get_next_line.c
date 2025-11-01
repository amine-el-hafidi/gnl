/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminel-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:53:04 by aminel-h          #+#    #+#             */
/*   Updated: 2025/11/01 14:15:09 by aminel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (read_bytes <= 0)
			break ;
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
	static char	*saved;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (free(saved), saved = NULL, NULL);
	saved = read_line(fd, saved);
	if (!saved)
		return (NULL);
	line = extract_line(saved);
	saved = update_saved(saved);
	return (line);
}
