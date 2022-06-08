#include "get_next_line.h"

int main (void)
{
    int fd;
	int	i;

	i = 0;
    printf ("%d\n", BUFFER_SIZE);
    fd = open("myfile.txt", O_RDONLY);
    if (fd < 0)
	    return (0);
	printf("|%s|", get_next_line(fd));
	i++;
	while (++i <= 6)
	{
		printf("%s|", get_next_line(fd));
	}
	close(fd);
}
