#include <libc.h>

int	main(void)
{
	printf("---------SIZE_VAR---------\n");
	printf("[sizeof(char)]		%zu\n", sizeof(char));
	printf("[sizeof(int)]		%zu\n", sizeof(int));
	printf("[sizeof(long)]		%zu\n", sizeof(long));
	printf("[sizeof(long long)]	%zu\n", sizeof(long long));
	printf("[sizeof(size_t)]	%zu\n", sizeof(size_t));
	printf("---------SIZE_POINTER---------\n");
	printf("[sizeof(char *)]	%zu\n", sizeof(char *));
	printf("[sizeof(int *)]		%zu\n", sizeof(int *));
	printf("[sizeof(long *)]	%zu\n", sizeof(long *));
	printf("[sizeof(long long *)]	%zu\n", sizeof(long long *));
	printf("[sizeof(size_t *)]	%zu\n", sizeof(size_t *));

	char	c[5];
	int		i[5];
	long	l[5];

	printf("---------VALUE_POINTER---------\n");
	printf("[char]%zu\n", &c[0]);
	printf("[char]%zu\n", &c[1]);
	printf("[int ]%zu\n", &i[0]);
	printf("[int ]%zu\n", &i[1]);
	printf("[long]%zu\n", &l[0]);
	printf("[long]%zu\n", &l[1]);
	return (0);
}
