/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:06:31 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/01/17 17:08:10 by rsaueia-         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;

	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
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
	while (*s2)
		newstr[i++] = *s2++;
	newstr[i] = '\0';
	if (!*newstr)
	{
		free(newstr);
		return (NULL);
	}
	return (newstr);
}
