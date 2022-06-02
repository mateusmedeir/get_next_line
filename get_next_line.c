#include "get_next_line.h"

char *get_next_line(int fd)
{
	int			counter;
	char		*new;
	static char	tmp[BUFFER_SIZE + 1];

	new = NULL;
	counter = read (fd, tmp, BUFFER_SIZE);
	tmp[counter] = '\0';
	new = put_the_line(tmp);
	return (new);
}
