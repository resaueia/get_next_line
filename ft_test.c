/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:20:36 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/01/04 17:23:29 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main()
{
	int	fd;
	char	buffer[100];
	int	byte_size;

	fd = open("test.txt", O_RDONLY | O_CREAT | O_APPEND);
	//write(fd, "ola", 3);
	while ((byte_size = read(fd, buffer, 5)))
	{
		printf("%d\n", byte_size);
		buffer[byte_size] = '\0';
		printf("%s\n",buffer);
	}
	return (0);
}

