/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:07:29 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/01/12 20:38:57 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	char	*test;
	size_t	i;
	size_t	j;

	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	test = newstr;
	i = 0;
	j = 0;
	if (newstr == NULL)
		return (NULL);
	while (s1[i])
	{
		*newstr = s1[i];
		newstr++;
		i++;
	}
	while (s2[j])
	{
		*newstr = s2[j];
		newstr++;
		j++;
	}
	*newstr = '\0';
	return (test);
}

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
}

char	*get_surplus(char *storage)
{
	int	count;
	int	i;
	int	j;
	char	*line;

	count = 0;
	i = 0;
	j = 0;
	if (storage)
		return (NULL);
	while (storage[count] != '\n')
		count++;
	while (storage[count + i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
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
	line = (char *)malloc(sizeof(char) * count);
	if (!line)
		return (NULL);
	while (i < count)
	{
		line[i] = str[i];
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
	while (bytes_read > 0 || ft_strchr(storage) == 1 )
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		//if (bytes_read == 0)
		//	free (buffer);
		//	return (storage);
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	line = process_line(storage);
	//temp = &storage;
	storage = get_surplus(storage);
	//free(temp);
	return (line);
}

int	main()
{
	int	fd;
	char	buffer[100];
	int	byte_size;

	fd = open("test.txt", O_RDONLY | O_CREAT);
	while ((byte_size = read(fd, buffer, 5)))
	{
		printf("%d\n", byte_size);
		buffer[byte_size] = '\0';
		printf("%s\n", buffer);
	}
	return(0);
}
