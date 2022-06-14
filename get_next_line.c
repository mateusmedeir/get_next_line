/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedeiro <mmedeiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:45:45 by mmedeiro          #+#    #+#             */
/*   Updated: 2022/06/14 12:59:19 by mmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			counter;
	char		*new;
	static char	*res;

	counter = 1;
	while (counter > 0 && find_next_line(res) != 1)
	{
		new = malloc((BUFFER_SIZE + 1) * sizeof(char));
		counter = read (fd, new, BUFFER_SIZE);
		if (counter == -1)
			break ;
		new[counter] = '\0';
		res = join_strings(res, new);
		free(new);
	}
	if (counter == -1)
		return (NULL);
	new = put_the_line(res);
	res = cat_res(res);
	return (new);
}
