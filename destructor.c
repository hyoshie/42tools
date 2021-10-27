#include <stdio.h>
#include <stdlib.h>

void	end(void)__attribute__((destructor));

void end(void)
{
	    system("leaks a.out");
}

int	main()
{
	char	*str;

	str = malloc(2);
	return (0);
}
