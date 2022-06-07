#include "get_next_line.h"

int find_next_line(char *s)
{
	if (!s)
		return (0);
    while (*s)
    {
        if (*s == '\n')
            return (1);
        s++;
    }
    return (0);
}

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
	new = malloc (size + 1);
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

char	*cat_res(char *tmp, char *res)
{
	char	*pointer;
	int	counter;

	if (res)
		free(res);
	counter = count_line(tmp);
	pointer = NULL;
	if (tmp[counter] == '\n' && tmp[counter + 1])
	{
		res = malloc(++counter);
		if (!res)
			return (NULL);
		pointer = res;
		while (tmp[counter])
			*res++ = tmp[counter++];
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
	while (*tmp && *tmp != '\n')
	{
		new[counter] = *tmp;
		counter++;
		tmp++;
	}
	if (*tmp == '\n')
		new[counter++] = '\n';
	new[counter] = '\0';
	return(new);
}
