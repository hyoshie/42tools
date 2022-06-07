#include <stdio.h>
#include "ft_printf.h"

void	end(void)__attribute__((destructor));

void end(void)
{
	    system("leaks a.out");
}

int    main()
{
	int    st;
	int    ft;
	char    *a = "42";
	char    *b = NULL;
	char    *c = "tokyo";

	st = printf("(st)%c %c %c\n", '0', 0, '1');
	ft = ft_printf("(ft)%c %c %c\n", '0', 0, '1');
	printf("(st)%d\n", st);
	printf("(ft)%d\n", ft);
	st = printf("(st)%s %s %s\n", a, b, c);
	ft = ft_printf("(ft)%s %s %s\n", a, b, c);
	printf("(st)%d\n", st);
	printf("(ft)%d\n", ft);
	st = printf("(st)%p %p\n", (void *)0, (void *)0);
	ft = ft_printf("(ft)%p %p\n", (void *)0, (void *)0);
	printf("(st)%d\n", st);
	printf("(ft)%d\n", ft);
	st = printf("(st)%i %i\n", 42, INT_MAX);
	ft = ft_printf("(ft)%i %i\n", 42, INT_MAX);
	printf("(st)%d\n", st);
	printf("(ft)%d\n", ft);
	st = printf("(st)%d %d\n", 42, INT_MAX);
	ft = ft_printf("(ft)%d %d\n", 42, INT_MAX);
	printf("(st)%d\n", st);
	printf("(ft)%d\n", ft);
	st = printf("(st)%x %x\n", 42, INT_MAX);
	ft = ft_printf("(ft)%x %x\n", 42, INT_MAX);
	printf("(st)%d\n", st);
	printf("(ft)%d\n", ft);
	st = printf("(st)%X %X\n", 42, INT_MAX);
	ft = ft_printf("(ft)%X %X\n", 42, INT_MAX);
	printf("(st)%d\n", st);
	printf("(ft)%d\n", ft);
	st = printf("(st)%%\n");
	ft = ft_printf("(ft)%%\n");
	printf("(st)%d\n", st);
	printf("(ft)%d\n", ft);
	st = printf("(st)%b\n");
	ft = ft_printf("(ft)%b\n");
	printf("(st)%d\n", st);
	printf("(ft)%d\n", ft);
}
