#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	*str;

	str = malloc(2);
	free(str);
	return (0);
}

void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void)
{
	if (system("leaks -q a.out > /dev/null"))
		system("leaks -q a.out");
}
