#include "get_next_line.h"

char	*put_the_line(char *tmp)
{
	int		counter;
	int		size;
	char	*new;

	size = 0;
	while (tmp[size] && tmp[size] != '\n')
		size++;
	new = malloc ((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	counter = 0;
	while (counter <= size)
	{
		new[counter] = tmp[counter];
		counter++;
	}
	new[counter] = '\0';
	return (new);
}
