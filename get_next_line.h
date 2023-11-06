/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matlopes <matlopes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:54:13 by matlopes          #+#    #+#             */
/*   Updated: 2023/11/06 13:45:59 by matlopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
int		ft_find_next_line(char *str);
char	*ft_put_the_line(char *res);
char	*ft_cat_res(char *res);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_file(int fd);
char	*get_next_line(int fd);

#endif
