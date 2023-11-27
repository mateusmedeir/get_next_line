/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:26:58 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/27 11:26:58 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	if (!s)
		return (counter);
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strchr(const char *s, int c)
{
	char	*pointer;

	pointer = (char *)s;
	while (*pointer && *pointer != c)
		pointer++;
	if (*pointer == c)
		return ((char *)pointer);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*pointer;
	int		counter;

	pointer = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!pointer)
		return (NULL);
	counter = 0;
	while (s1[counter] != '\0')
	{
		pointer[counter] = s1[counter];
		counter++;
	}
	pointer[counter] = '\0';
	return (pointer);
}
