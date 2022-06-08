#include "get_next_line.h"

#include <stdio.h>
char *get_next_line(int fd)
{
	int		counter;
	char		*new;
	char		*tmp;
	static char	*res;

	if (find_next_line(res))
	{
		new = put_the_line(res);
		res = cat_res(res + (count_line(res) + 1));
		return (new);
	}
	counter = 1;
	while (counter > 0 && find_next_line(res) != 1)
	{
		tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
		counter = read (fd, tmp, BUFFER_SIZE);
		tmp[counter] = '\0';
		res = join_strings(res, tmp);
	}
	free(tmp);
	new = put_the_line(res);
	res = cat_res(res + (count_line(res) + 1));
	return (new);
}
