#include "get_next_line.h"

int main (void)
{
    int     fd;
    int     count;
    char    *line = 0;

    printf("\n==========================================\n");
    printf("================== TEST ==================\n");
    printf("==========================================\n\n");

    count = 0;
    if (!(fd = open("bigalphabet.txt", O_RDONLY)))
    {
        printf("\nError in open\n");
        return (0);
    }
    while (1)
    {
        line = get_next_line(fd);
        if (!*line)
            break;
        count++;
        printf("|%s", line);
    }
}
