#include <stdio.h>
#include <stdlib.h>

// void	end(void)__attribute__((destructor));

// void end(void)
// {
// 	if (system("leaks a.out > /dev/null"))
// 		printf("\x1b[31mLEAKS\x1b[39m\n");
// }

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
