/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:41:23 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/27 11:52:56 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_put_the_line(char *res)
{
	int		counter;
	int		check;
	int		size;
	char	*line;

	size = 0;
	check = 0;
	while (res[size] && res[size] != '\n')
		size++;
	if (res[size] == '\n')
		check++;
	line = malloc((size + check + 1) * sizeof(char));
	if (!line)
		return (NULL);
	counter = 0;
	while (counter < size)
	{
		line[counter] = res[counter];
		counter++;
	}
	if (res[counter] == '\n')
		line[counter++] = '\n';
	line[counter] = '\0';
	return (line);
}

char	*ft_cat_res(char *res)
{
	char	*new_res;
	int		counter;
	int		size;

	size = 0;
	while (res[size] && res[size] != '\n')
		size++;
	if (!res[size])
	{
		free(res);
		return (NULL);
	}
	size++;
	new_res = malloc(((ft_strlen(res) - size) + 1) * sizeof(char));
	if (!new_res)
		return (NULL);
	counter = -1;
	while (res[size + ++counter])
		new_res[counter] = res[size + counter];
	new_res[counter] = '\0';
	free(res);
	return (new_res);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*pointer;
	int		counter;

	counter = 0;
	pointer = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!pointer)
		return (NULL);
	if (s1)
	{
		while (s1[counter])
		{
			pointer[counter] = s1[counter];
			counter++;
		}
		free(s1);
	}
	while (*s2)
		pointer[counter++] = *s2++;
	pointer[counter] = '\0';
	if (!*pointer)
	{
		free(pointer);
		return (NULL);
	}
	return (pointer);
}

char	*ft_read_file(int fd)
{
	int			counter;
	char		*line;
	static char	*res;

	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	counter = 1;
	while (counter > 0 && (!res || !ft_strchr(res, '\n')))
	{
		counter = read(fd, line, BUFFER_SIZE);
		if (counter < 0)
		{
			free(line);
			return (NULL);
		}
		line[counter] = '\0';
		res = ft_strjoin_free(res, line);
	}
	free(line);
	if (!res)
		return (NULL);
	line = ft_put_the_line(res);
	res = ft_cat_res(res);
	return (line);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (ft_read_file(fd));
}
