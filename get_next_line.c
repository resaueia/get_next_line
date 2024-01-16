/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:07:29 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/01/15 17:18:33 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	ft_strchr(char *str, char c)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == c)
			return (1);
		count++;
	}
	if (c == '\0')
		return (0);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	if (newstr == NULL)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[j + i] = '\0';
	return (newstr);
}
/*
char	line_reader(const *str)
{
	while (*str)
	{
		if (*str == '\n')
		{
			str++;
			break;
		}
		str++;
	}
	return (str);
}*/

char	*get_surplus(char *storage)
{
	int	count;
	int	i;
	int	j;
	char	*line;

	count = 0;
	i = 0;
	j = 0;
	if (!storage)
		return (NULL);
	while (storage[count] != '\n')
		count++;
	while (storage[count + i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (storage[i])
	{
		line[j] = storage[count + j];
		j++;
	}
	line[j] = '\0';
	free(storage);
	return (line);
}

char	*process_line(char *storage)
{
	int	count;
	int	i;
	char	*line;

	count = 0;
	i = 0;
	while (storage[count] != '\0')
	{
		if (storage[count] == '\n')
		{
			count++;
			break;
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

char	*get_next_line(int fd)
{
	static char	*storage;
	char	*buffer;
	char	*line;
	int	bytes_read;

	bytes_read = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes_read > 0 || ft_strchr(storage, '\n') == 1 )
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	line = process_line(storage);
	storage = get_surplus(storage);
	return (line);
}

int	main()
{
	int	fd;
	char	buffer[100];
	int	byte_size;

	fd = open("test.txt", O_RDONLY | O_CREAT);
	if (fd == -1)
	{
		perror("Error opening the file");
		return 1;  // Or handle the error appropriately
	}

	printf("%s", get_next_line(fd));
	return(0);
}
