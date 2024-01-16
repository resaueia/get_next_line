/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:07:29 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/01/16 19:40:15 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}


int	ft_strchr(char *str, char c)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] && str[count] != '\0')
	{
		if (str[count] == c)
			return (1);
		count++;
	}
	if (c == '\0')
		return (0);
	return (0);
}
/*
int	ft_strrchr(char *s, int c)
{
	int	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len - 1] == c)
			return (1);
		len--;
	}
	if (c == '\0')
		return (0);
	return (0);
}
*/
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
	if (s1)
	{
		while (s1[i])
		{
			newstr[i] = s1[i];
			i++;
		}
		free(s1);
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
	int	surplus;
	char	*line;

	count = 0;
	//i = 1;
	i = 0;
	j = 0;
	if (!storage)
		return (NULL);
	while (storage[count] != '\0' && storage[count] != '\n')
		count++;
	if (storage[count] == '\n')
		count++;
	while (storage[i])
		i++;
	surplus = i - count;
	line = malloc(sizeof(char) * surplus + 1);
	line[surplus] = '\0';
	/*
	while (storage[count + i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	*/
	while (count < i)
	{
		line[j] = storage[count + j];
		j++;
	}
	//line[j] = '\0';
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
	line = (char *)malloc(sizeof(char) * (count)); //count + 1
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
	//static char	*storage = "";
	static char	*storage = NULL;
	char	*buffer;
	char	*line;
	int	bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bytes_read = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = 0;

	while (bytes_read > 0 && !ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	if (storage && storage[0] == '\0')
	{
		if (storage)
			free(storage);
		return (NULL);
	}
	if (!storage)
		return (NULL);
	line = process_line(storage);
	storage = get_surplus(storage);
	return (line);
}

int	main()
{
	int	fd;
	char	*buffer;
//	int	byte_size;
	int 	test = 10;


//	write(1, "OPAA\n", 5);
	fd = open("test.txt", O_RDONLY);
	//printf("%d", fd);
	buffer = get_next_line(fd);
	while (buffer && test--)
	{		
		printf("%s", buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	if (buffer)
		free(buffer);
	close(fd);
	return(0);
}
