/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:07:29 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/01/08 19:44:52 by rsaueia-         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char	*storage;
	char	*buffer;
	int	bytes_read;

	bytes_read = 0;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			free (buffer);
			return (NULL);
		storage = ft_strjoin(storage, buffer);
		while (*buffer)
		{
			if (*buffer == '\n')
				break;
		}
	return (buffer);
	}
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
