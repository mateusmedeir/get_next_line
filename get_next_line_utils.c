#include "get_next_line.h"

int	count_line(char *s)
{
	int	counter;

	counter = 0;
	while (s[counter] && s[counter] != '\n')
		counter++;
	return (counter);
}

char	*put_the_line(char *tmp)
{
	int		counter;
	int		size;
	char	*new;

	size = count_line(tmp);
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

char	*cat_res(char *tmp)
{
	char	*res;
	char	*pointer;
	int	counter;

	counter = count_line(tmp);
	res = NULL;
	if (tmp[counter] == '\n' && tmp[counter + 1])
	{
		res = malloc((++counter) * sizeof(char));
		if (!res)
			return (NULL);
		pointer = res;
		while (tmp[counter])
		{
			*res = tmp[counter];
			res++;
			counter++;
		}
	return (pointer);
	}
}

char	*join_strings(char *res, char *tmp)
{
	if (!res)
		return(put_the_line(tmp));
}
