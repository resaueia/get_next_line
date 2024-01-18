/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:07:29 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/01/17 21:48:43 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_surplus(char *storage)
{
	int	count;
	int	i;
	int	j;
	char		*line;

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
	static char	*storage = NULL;
	char	*buffer;
	int	bytes_read;

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
	char	*str;


	 1° test
	printf("Test 1\n\n");
	fd = open("files/empty", O_RDWR);
	str = get_next_line(1000);
	str = get_next_line(-1);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}

	// 2° test
	printf("Test 2\n\n");
	fd = open("files/empty", O_RDWR);
	str = get_next_line(fd);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}
	// 3° test
	printf("Test 3\n\n");
	fd = open("files/nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}

	// 4° test
	printf("Test 4\n\n");
	fd = open("files/41_no_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}
	// 5° test
	printf("Test 5\n\n");
	fd = open("files/41_with_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}

	// 6° test
	printf("Test 6\n\n");
	fd = open("files/42_no_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}

	// 7° test
	printf("Test 7\n\n");
	fd = open("files/42_with_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}

	// 8° test
	printf("Test 8\n\n");
	fd = open("files/43_no_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}

	// 9° test
	printf("Test 9\n\n");
	fd = open("files/43_with_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}

	// 10° test
	printf("Test 10\n\n");
	fd = open("files/multiple_nlx5", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}

	// 11° test
	printf("Test 11\n\n");
	fd = open("files/multiple_line_no_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}

	// 12° test
	printf("Test 12\n\n");
	fd = open("files/multiple_line_with_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}

	// 13° test
	printf("Test 13\n\n");
	fd = open("files/alternate_line_nl_no_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}

	// 14° test
	printf("Test 14\n\n");
	fd = open("files/alternate_line_nl_with_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}

	// 15° test
	printf("Test 15\n\n");
	fd = open("files/big_line_no_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}

	// 16° test
	printf("Test 16\n\n");
	fd = open("files/big_line_with_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	close(fd);
}*/
