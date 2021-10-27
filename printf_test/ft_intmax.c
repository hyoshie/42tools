#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"

#define LEN (size_t)INT_MAX

int	main()
{
	char	*str;
	int		ret;

	str = (char *)malloc(LEN + 1);
	if (!str)
		return (1);
	memset(str, 'a', LEN);
	str[LEN] = '\0';

	ret = ft_printf("%s", str);
	printf("\nret = %d\n", ret);

	return (0);
}

