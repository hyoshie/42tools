#include <libc.h>

int main(int argc, char **argv) {
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

  char c[5];
  int i[5];
  long l[5];
  extern char **environ;
  char *heap = malloc(42);

  printf("---------VALUE_POINTER---------\n");
  printf("[char]%p\n", &c[0]);
  printf("[char]%p\n", &c[1]);
  printf("[int ]%p\n", &i[0]);
  printf("[int ]%p\n", &i[1]);
  printf("[long]%p\n", &l[0]);
  printf("[long]%p\n", &l[1]);
  printf("[\"42\"]%p\n", "42");
  printf("[argc]%p\n", &argc);
  printf("[argv]%p\n", &argv);
  printf("[environ]%p\n", &environ);
  printf("[malloc]%p\n", heap);
  return (0);
}
