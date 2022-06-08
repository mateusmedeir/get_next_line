#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		find_next_line(char *s);
int		count_line(char *s);
char	*put_the_line(char *s);
char	*cat_res(char *res);
char	*join_strings(char *res, char *tmp);

#endif
