#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd)
{
	char	*new;
	char	*tmp;
	size_t	buf;

	buf = BUFFER_SIZE;
	new = malloc ((buf) * sizeof (*new));
	if (!new)
		return (NULL);
	read (fd, new, buf - 1);
	if (!new)
		return (NULL);
	new[buf - 1] = '\0';
	return (new);
}

int	main (void)
{
	int fd;
	char	*new;

	printf ("%d\n", BUFFER_SIZE);
	fd = open("myfile.txt", O_CREAT | O_WRONLY, 0600);
	if (fd == -1)
		return (0);
	write(fd, "Hello World\nHello Everyone\n", BUFFER_SIZE);
	close (fd);
	fd = open("myfile.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	new = get_next_line(fd);
	printf("%s", new);
}
