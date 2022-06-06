#include "get_next_line.h"

char *get_next_line(int fd)
{
	int		counter;
	char		*new;
	char		*tmp;
	static char	*res;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	counter = read (fd, tmp, BUFFER_SIZE);
	tmp[counter] = '\0';
	counter = find_next_line(tmp);
	new = join_strings(res, tmp);
	res = cat_res(tmp, res);
	return (new);
}
