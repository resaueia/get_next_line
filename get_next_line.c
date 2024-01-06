/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:07:29 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/01/06 20:17:23 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	*storage;
	char	*line;
	char	*buffer;
	int	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break;
		storage = join"?"



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
