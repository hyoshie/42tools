#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define LENGTH (size_t)INT_MAX + 5


char *strbig(void)
{
	char* longstr;

	printf("creating long string...\n");
	longstr = malloc(LENGTH);
	memset(longstr, 'a', LENGTH - 2);
	longstr[LENGTH - 2] = 'b';
	longstr[LENGTH - 1] = '\0';
	return (longstr);
}

#define BUFFER INT_MAX

void	putstr_fd(char *str, int fd)
{
	size_t	len;

	if (!str)
		return ;
	len = strlen(str);
	while (len > BUFFER)
	{
		write(STDOUT_FILENO, str, BUFFER);
		// write(STDOUT_FILENO, str, strlen(str));
		len -= BUFFER;
		str += BUFFER;
	}
	write(STDOUT_FILENO, str, len);
}

int main(int argc, char* argv[])
{
	char	str[INT_MAX];
	// char	str[LONG_MAX];


	char	*longstr = strbig();
	// write(STDOUT_FILENO, longstr, LENGTH);
	putstr_fd(longstr, STDOUT_FILENO);
	printf("check\n");
	return 0;
}
