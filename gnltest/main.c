#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd;
	int	loop;
	char	*str;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		loop = 1;
		while ((str = get_next_line(fd)) != NULL)
		{
			printf("[%2d]called : %s", loop, str);
			free(str);
			loop++;
		}
	}
	return (0);
}
