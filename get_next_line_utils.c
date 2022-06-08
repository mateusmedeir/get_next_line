#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t  counter;

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

int	count_line(char *s)
{
	int	counter;

	if (!s)
		return (0);
	counter = 0;
	while (s[counter] != '\n' && s[counter])
		counter++;
	return (counter);
}

char	*put_the_line(char *s)
{
	int		counter;
	int		size;
	char	*new;

	size = count_line(s);
	new = malloc (size + 1);
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

	if (!res)
		return (NULL);
	new = malloc(ft_strlen(res) + 1);
	if (!new)
		return (NULL);
	counter = 0;
	while (res[counter])
	{
		new[counter] = res[counter];
		counter++;
	}
	new[counter] = '\0';
	return (new);
}

char	*join_strings(char *res, char *tmp)
{
	char	*new;
	int	counter;

	counter = 0;
	new = malloc ((count_line(res) + ft_strlen(tmp) + 1));
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
