#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t  counter;

	if (!s)
		return(0);
    counter = 0;
    while (s[counter] != '\0')
        counter++;
    return (counter);
}

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

char	*put_the_line(char *s)
{
	int		counter;
	int		size;
	char	*new;

	size = 0;
	while (s[size] && s[size] != '\n')
		size++;
	new = malloc (size + 2);
	if (!new)
		return (NULL);
	counter = 0;
	while (counter <= size)
	{
		new[counter] = s[counter];
		counter++;
	}
	new[counter] = '\0';
	return (new);
}

char	*cat_res(char *res)
{
	char	*new;
	int	counter;
	int	size;

	size = 0;
	while (res[size] && res[size] != '\n')
		size++;
	if (!res[size])
		return (NULL);
	size++;
	new = malloc(ft_strlen(res) - size + 1);
	if (!new)
		return (NULL);
	counter = 0;
	while (res[size + counter])
	{
		new[counter] = res[size + counter];
		counter++;
	}
	new[counter] = '\0';
	free(res);
	return (new);
}

char	*join_strings(char *res, char *tmp)
{
	char	*new;
	int	counter;

	counter = 0;
	new = malloc ((ft_strlen(res) + ft_strlen(tmp) + 1));
	if (!new)
		return (NULL);
	if (res)
	{
		while (*res)
		{
			new[counter] = *res;
			res++;
			counter++;
		}
	}
	while (*tmp)
	{
		new[counter] = *tmp;
		counter++;
		tmp++;
	}
	new[counter] = '\0';
	return(new);
}
