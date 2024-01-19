/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:07:29 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/01/18 19:25:12 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_surplus(char *storage)
{
	int		count;
	int		i;
	int		j;
	char	*line;

	count = 0;
	i = 0;
	j = -1;
	if (!storage)
		return (NULL);
	while (storage[count] != '\0' && storage[count] != '\n')
		count++;
	if (storage[count] == '\n')
		count++;
	while (storage[count + i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (++j < i)
		line[j] = storage[count + j];
	line[j] = '\0';
	free(storage);
	return (line);
}

char	*process_line(char *storage)
{
	int		count;
	int		i;
	char	*line;

	count = 0;
	i = 0;
	while (storage[count] != '\0')
	{
		if (storage[count] == '\n')
		{
			count++;
			break ;
		}
		count++;
	}
	line = (char *)malloc(sizeof(char) * (count + 1));
	if (!line)
		return (NULL);
	while (i < count)
	{
		line[i] = storage[i];
		i++;
	}
	line[count] = '\0';
	return (line);
}

int	validate_storage(char *storage)
{
	if (storage && storage[0] == '\0')
	{
		if (storage)
			free(storage);
		return (0);
	}
	return (1);
}

char	*read_line(int fd)
{
	int			bytes_read;
	static char	*storage = NULL;
	char		*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	if (!(storage && validate_storage(storage)))
		return (NULL);
	buffer = process_line(storage);
	storage = get_surplus(storage);
	return (buffer);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	return (read_line(fd));
}
/*
#include <stdio.h>
int main()
{
	int		fd;
	int	tracker = 4;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	while (tracker > 0)
	{
		printf("%s", get_next_line(fd));
		tracker--;
	}
	return (0);
}
*/

/* This project enlightens us on the use of static functions and coaxes us
   into writing a code for reading a given file line by line whilst dealing
   with possible memory leaks. The code written should be able to always
   return a line, regardless of how many bytes have been read past it. */
