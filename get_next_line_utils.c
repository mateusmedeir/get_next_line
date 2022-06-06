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

int	find_next_line(char *tmp)
{
	while (*tmp)
	{
		if (*tmp == '\n')
			return (0);
		tmp++;
	}
	return (1);
}

char	*cat_res(char *tmp, char *res)
{
	char	*pointer;
	int	counter;

	counter = count_line(tmp);
	if (res)
		free(res);
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
		if (tmp[counter] == '\n')
			return (NULL);
	}
	return (pointer);
}

char	*join_strings(char *res, char *tmp)
{
	char	*new;
	int	counter;

	if (!res)
		return(put_the_line(tmp));
	counter = 0;
	new = malloc ((count_line(res) + count_line(tmp) + 1));
	if (!new)
		return (NULL);
	while (*res)
	{
		new[counter] = *res;
		res++;
		counter++;
	}
	if(*res != '\n')
	{
		while (*tmp && *tmp != '\n')
		{
			new[counter] = *tmp;
			counter++;
			tmp++;
		}
	}
	if (*tmp == '\n' || *res == '\n')
		new[counter++] = '\n';
	new[counter] = '\0';
	return(new);
}
