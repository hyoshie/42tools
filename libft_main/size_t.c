#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
//#include "libft.h"

#define LENGTH (size_t)INT_MAX + 5

int	main()
{
	char	*str;

	str = malloc(LENGTH);
	memset(str, 'a', LENGTH - 1);
	str[LENGTH - 1] = '\0';
	printf("%d\n", printf("%s\n", str));
	return (0);
}

