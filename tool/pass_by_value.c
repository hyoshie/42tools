#include <stdio.h>

//Color
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[39m"

void	swap(int a, int b)
{
	printf(YELLOW"-----Before:Swap-----\n"RESET);
	printf("[a]	%d\n[&a]	%p\n", a, &a);
	printf("[b]	%d\n[&b]	%p\n", b, &b);
	int	tmp;

	tmp = a;
	a = b;
	b = tmp;
	printf(YELLOW"-----After :Swap-----\n"RESET);
	printf("[a]	%d\n[&a]	%p\n", a, &a);
	printf("[b]	%d\n[&b]	%p\n", b, &b);
}

int	main(int argc, char **argv)
{
	int	x = 42;
	int	y = 100;

	printf(GREEN"-----Before:Main-----\n"RESET);
	printf("[x]	%d\n[&x]	%p\n", x, &x);
	printf("[y]	%d\n[&y]	%p\n", y, &y);
	swap(x, y);
	printf(GREEN"-----After :Main-----\n"RESET);
	printf("[x]	%d\n[&x]	%p\n", x, &x);
	printf("[y]	%d\n[&y]	%p\n", y, &y);

	return (0);
}
