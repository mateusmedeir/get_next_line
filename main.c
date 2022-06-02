#include "get_next_line.h"

int main (void)
{
    int fd;

    printf ("%d\n", BUFFER_SIZE);
    fd = open("myfile.txt", O_RDONLY);
    if (fd == -1)
        return (0);
	printf("|%s", get_next_line(fd));
	printf("|%s", get_next_line(fd));
	printf("|%s", get_next_line(fd));
	close(fd);
}
