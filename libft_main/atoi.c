#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *ptr);

int	main(void)
{
	printf("st :  %d\n",    atoi("0"));
	printf("ft :  %d\n", ft_atoi("0"));
	printf("st :  %d\n",    atoi("9223372036854775806"));
	printf("ft :  %d\n", ft_atoi("9223372036854775806"));
	printf("st :  %d\n",    atoi("9223372036854775807"));
	printf("ft :  %d\n", ft_atoi("9223372036854775807"));
	printf("st :  %d\n",    atoi("9223372036854775808"));
	printf("ft :  %d\n", ft_atoi("9223372036854775808"));
	printf("st :  %d\n",    atoi("-9223372036854775807"));
	printf("ft :  %d\n", ft_atoi("-9223372036854775807"));
	printf("st :  %d\n",    atoi("-9223372036854775808"));
	printf("ft :  %d\n", ft_atoi("-9223372036854775808"));
	printf("st :  %d\n",    atoi("-9223372036854775809"));
	printf("ft :  %d\n", ft_atoi("-9223372036854775809"));
								//9223372036854775807
}
