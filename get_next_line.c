/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:41:23 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/08 12:55:26 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd)
{
	int			counter;
	char		*line;
	static char	*res;

	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	counter = 1;
	while (counter > 0 && !ft_find_next_line(res))
	{
		counter = read(fd, line, BUFFER_SIZE);
		if (counter < 0)
		{
			free(line);
			return (NULL);
		}
		line[counter] = '\0';
		res = ft_strjoin(res, line);
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
