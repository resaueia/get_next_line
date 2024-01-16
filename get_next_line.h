/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:01:13 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/01/15 19:08:34 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strlen(char *str);
int	ft_strchr(char *str, char c);
char	*get_surplus(char *storage);
char	*process_line(char *storage);

#include <unistd.h>
#include <stdlib.h>

#endif
