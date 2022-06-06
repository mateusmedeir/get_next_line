#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd);
char *put_the_line(char *tmp);
char    *cat_res(char *tmp, char *res);
char    *join_strings(char *res, char *tmp);
int     find_next_line(char *tmp);

#endif
