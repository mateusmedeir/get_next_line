#include "get_next_line.h"

int main (void)
{
    int		fd;
	int		count;
	char	*line = 0;
	
	printf("\n==========================================\n");
	printf("================= TEST 1 =================\n");
	printf("==========================================\n\n");
	
	count = 0;
	if (!(fd = open("alphabet.txt", O_RDONLY)))
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
	if(count == 17)
		printf("\nRight number of lines\n");
	else
		printf("\nWrong number of lines. file = 17, your gnl = %d\n", count);
	free(line);
	close(fd);

    printf("\n==========================================\n");
    printf("================= TEST 2 =================\n");
    printf("==========================================\n\n");

	count = 0;
    if (!(fd = open("emptylines.txt", O_RDONLY)))
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
	if(count == 4)
        printf("\nRight number of lines\n");
    else
        printf("\nWrong number of lines. file = 4, your gnl = %d\n", count);
    free(line);
    close(fd);

    printf("\n==========================================\n");
    printf("================= TEST 3 =================\n");
    printf("==========================================\n\n");

    if (!(fd = open("emptyfile.txt", O_RDONLY)))
    {
        printf("\nError in open\n");
        return (0);
    }
    line = get_next_line(fd);
    if (!*line)
		printf("Empty line\n");
    free(line);
    close(fd);

	printf("\n==========================================\n");
    printf("================ BIG LINE ================\n");
    printf("==========================================\n\n");

    count = 0;
    if (!(fd = open("bigline.txt", O_RDONLY)))
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
    }
	printf("NUMBER OF LINES = %d\n", count);
    if(count == 1)
        printf("\nRight number of lines\n");
    else
        printf("\nWrong number of lines. file = 1");
    free(line);
    close(fd);

	printf("\n==========================================\n");
    printf("================ BIG FILE ================\n");
    printf("==========================================\n\n");

    count = 0;
    if (!(fd = open("bigfile.txt", O_RDONLY)))
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
    }
	printf("NUMBER OF LINES = %d\n", count);
    if(count == 2916)
        printf("\nRight number of lines\n\n");
    else
        printf("\nWrong number of lines. file = 2916\n\n");
    free(line);
    close(fd);
}
