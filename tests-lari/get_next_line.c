/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:47:34 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/01/04 19:48:38 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void freefunct(str, str_buffer)
{
	char *temp
	temp = join(str, str_buffer)
	free(str);
	retorno temp

char	*get_next_line(int fd)
{
	static str;
	char *str_buffer; = '42\n24\naser\nasef\naaser'

	while (não chega no \n)
		int bytes_readed = read(fd, str_buffer, BUFFER_SIZE);
		str = free_funct(str, str_buffer);
	função -> ler str até \n + 1(que é o próprio \n);
		isso que vc vai retornar;
	função2 ->
}

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char *gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		printf("GNL -> %s.\n", gnl);
		free(gnl);
		gnl = get_next_line(fd);
	}
}
