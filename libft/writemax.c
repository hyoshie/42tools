#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LENGTH (size_t) INT_MAX + 5

char *strbig(void) {
  char *longstr;

  printf("creating long string...\n");
  longstr = malloc(LENGTH);
  memset(longstr, 'a', LENGTH - 2);
  longstr[LENGTH - 2] = 'b';
  longstr[LENGTH - 1] = '\0';
  return (longstr);
}

#define BUFFER INT_MAX

size_t ft_strlen(char *str) {
  int i;

  i = 0;
  while (str[i]) {
    i++;
    if (i < 0)
		printf("[i]%d\n", i);
  }
  return (i);
}

int main(int argc, char *argv[]) {
  char *longstr = strbig();

  ft_strlen(longstr);
  return 0;
}
