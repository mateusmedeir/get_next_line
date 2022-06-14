#include "get_next_line.h"
#include <stdio.h>
int	main(void)
{
	int i;

	i = open("empty", O_RDONLY);
	printf("%d\n", i);
}
