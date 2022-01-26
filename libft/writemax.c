#include "../libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define LENGTH (size_t)INT_MAX + 5

char* longstr;

char *strbig(void)
{
	printf("creating long string...\n");
	longstr = malloc(LENGTH);
	memset(longstr, 'a', LENGTH - 2);
	longstr[LENGTH - 2] = 'b';
	longstr[LENGTH - 1] = '\0';
	return (longstr);
}

int main(int argc, char* argv[])
{
	write(STDOUT_FILENO, longstr, LENGTH);
	printf("check\n");
	return 0;
}
