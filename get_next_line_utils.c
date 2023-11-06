/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:56:50 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/06 13:48:28 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

int	ft_find_next_line(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

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
	new_res = malloc((ft_strlen(res) - size + 1) * sizeof(char));
	if (!new_res)
		return (NULL);
	counter = 0;
	while (res[size + counter])
	{
		new_res[counter] = res[size + counter];
		counter++;
	}
	new_res[counter] = '\0';
	free(res);
	return (new_res);
}

char	*ft_strjoin(char *s1, char *s2)
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
