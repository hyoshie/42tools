/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3argfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:22:42 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/24 14:44:30 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//Color
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[39m"

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void	my_test_memmove(char *dest1, char *dest2,const char *src, size_t size)
{
	pid_t pid;
	pid_t wait_pid;
	int     status_expect = 0;
	int     status_actual = 0;

	char*	expect;
	char*	actual;

	printf("====test(%s,%s,%s,%zu)\n",dest1, dest2, src, size);
	pid = fork();
	if (pid == 0)
	{
		memmove(dest1, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_expect);
	}

	pid = fork();
	if (pid == 0)
	{
		ft_memmove(dest2, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_actual);
	}

	assert(WIFEXITED(status_expect) == WIFEXITED(status_actual));
	assert(WIFSIGNALED(status_expect) == WIFSIGNALED(status_actual));
	if (WIFEXITED(status_expect))
	{
		if (dest1 == NULL && dest2 == NULL)
		{
			printf("  Returned NULL \n");
			assert(dest1 == dest2);
		}
		else
		{
			memmove(dest1, src, size);
			ft_memmove(dest2, src, size);
			printf("  %s：expect\n", dest1);
			printf("  %s：actual\n", dest2);
			assert(!strncmp(dest1, dest2, size));
		}
	}
	else
	{
		printf("  Sig Abort \n");
		printf("  WTERMSIG:%d\n",WTERMSIG(status_actual));
	}
	free(dest1);
	free(dest2);
}

void	testmain_memmove(void)
{
	puts("-----TEST MEMMOVE-----\n");

	char *dest1;
	char *dest2;
	char *src = strdup(" World");
	size_t	size = 6;

	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test_memmove(dest1, dest2, src, size);

	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test_memmove(dest1, dest2, NULL, size);


	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test_memmove(dest1, dest2, NULL, 1);

	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test_memmove(dest1, dest2, NULL, 0);

	my_test_memmove(NULL, NULL, src, size);
	my_test_memmove(NULL, NULL, src, 1);
	my_test_memmove(NULL, NULL, src, 0);


	my_test_memmove(NULL, NULL, NULL, size);
	my_test_memmove(NULL, NULL, NULL, 1);
	my_test_memmove(NULL, NULL, NULL, 0);

	free(src);
}
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void	my_test_strlcat(char *dest1, char *dest2,const char *src, size_t size)
{

	pid_t pid;
	pid_t wait_pid;
	int     status_expect = 0;
	int     status_actual = 0;

	size_t	expect;
	size_t	actual;

	printf("====test(%s,%s,%s,%zu)\n",dest1, dest2, src, size);
	pid = fork();
	if (pid == 0)
	{
		expect = strlcat(dest1, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_expect);
	}

	pid = fork();
	if (pid == 0)
	{
		actual = ft_strlcat(dest2, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_actual);
	}

	assert(WIFEXITED(status_expect) == WIFEXITED(status_actual));
	assert(WIFSIGNALED(status_expect) == WIFSIGNALED(status_actual));
	if (WIFEXITED(status_expect))
	{
		expect = strlcat(dest1, src, size);
		actual = ft_strlcat(dest2, src, size);
		printf("  %zu：expect\n", expect);
		printf("  %zu：actual\n", actual);
		assert(expect == actual);
	}
	else
	{
		printf(" Sig Abort \n");
		printf(" WTERMSIG:%d\n",WTERMSIG(status_actual));
	}
	free(dest1);
	free(dest2);
}

void	testmain_strlcat(void)
{

	char *dest1;
	char *dest2;
	char *src = strdup(" World");
	size_t	size = 6;

	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test_strlcat(dest1, dest2, src, size);

	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test_strlcat(dest1, dest2, NULL, size);

	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test_strlcat(dest1, dest2, NULL, 1);// セグフォが起きるが正しい

	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test_strlcat(dest1, dest2, NULL, 0);// セグフォが起きるが正しい

	my_test_strlcat(NULL, NULL, src, size);
	my_test_strlcat(NULL, NULL, src, 1);// セグフォが起きるが正しい
	// my_test_strlcat(NULL, NULL, src, 0);// セグフォが起きないが正しい

	my_test_strlcat(NULL, NULL, NULL, size);
	my_test_strlcat(NULL, NULL, NULL, 1);// セグフォが起きるが正しい
	my_test_strlcat(NULL, NULL, NULL, 0);// セグフォが起きるが正しい
	free(src);
}


#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void	my_test_strlcpy(char *dest1, char *dest2,char *src, size_t size)
{

	pid_t pid;
	pid_t wait_pid;
	int     status_expect = 0;
	int     status_actual = 0;

	size_t	expect;
	size_t	actual;

	printf("====test(%s,%s,%s,%zu)\n",dest1, dest2, src, size);
	pid = fork();
	if (pid == 0)
	{
		expect = strlcpy(dest1, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_expect);
	}

	pid = fork();
	if (pid == 0)
	{
		actual = ft_strlcpy(dest2, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_actual);
	}

	assert(WIFEXITED(status_expect) == WIFEXITED(status_actual));
	assert(WIFSIGNALED(status_expect) == WIFSIGNALED(status_actual));
	if (WIFEXITED(status_expect))
	{
		expect = strlcpy(dest1, src, size);
		actual = ft_strlcpy(dest2, src, size);
		printf("  %zu：expect\n", expect);
		printf("  %zu：actual\n", actual);
		assert(expect == actual);
	}
	else if(WIFSIGNALED(status_expect))
	{
		printf(" Sig Abort \n");
		assert(WTERMSIG(status_actual) == WTERMSIG(status_expect));
		printf(" WTERMSIG:%d\n",WTERMSIG(status_actual) );
	}
	free(dest1);
	free(dest2);
}

void	testmain_strlcpy(void)
{

	char *dest1;
	char *dest2;
	char *src = strdup(" World");
	size_t	size = 6;

	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test_strlcpy(dest1, dest2, src, size+100);

	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test_strlcpy(dest1, dest2, src, size);


	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test_strlcpy(dest1, dest2, src, 1);

	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test_strlcpy(dest1, dest2, src, 0);

	dest1 = strdup("");
	dest2 = strdup("");
	my_test_strlcpy(dest1, dest2, src, size+100);

	dest1 = strdup("");
	dest2 = strdup("");
	my_test_strlcpy(dest1, dest2, src, size);


	dest1 = strdup("");
	dest2 = strdup("");
	my_test_strlcpy(dest1, dest2, src, 1);

	dest1 = strdup("");
	dest2 = strdup("");
	my_test_strlcpy(dest1, dest2, src, 0);

	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test_strlcpy(dest1, dest2, NULL, size+100);

	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test_strlcpy(dest1, dest2, NULL, size);

	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test_strlcpy(dest1, dest2, NULL, 1);

	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test_strlcpy(dest1, dest2, NULL, 0);

	my_test_strlcpy(NULL, NULL, src, size);
	my_test_strlcpy(NULL, NULL, src, 1);
	my_test_strlcpy(NULL, NULL, src, 0);

	my_test_strlcpy(NULL, NULL, NULL, size);
	my_test_strlcpy(NULL, NULL, NULL, 1);
	my_test_strlcpy(NULL, NULL, NULL, 0);
	free(src);
}


#include <string.h>
#include <xlocale.h>
#include <stdio.h>
#include <assert.h>

// void	my_test_strnstr(const char *haystack, const char *needle, size_t len)
// {

// 	pid_t	pid;
// 	pid_t	wait_pid;
// 	int     status_expect = 0;
// 	int     status_actual = 0;
// 	char	*expect;
// 	char	*actual;

// 	printf("====test(%s,%s,%zu)\n",haystack, needle, len);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		expect = strnstr(haystack, needle, len);
// 		exit(0);
// 	}
// 	else
// 	{
// 		wait_pid = wait(&status_expect);
// 	}

// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		actual = ft_strnstr(haystack, needle, len);
// 		exit(0);
// 	}
// 	else
// 	{
// 		wait_pid = wait(&status_actual);
// 	}

// 	assert(WIFEXITED(status_expect) == WIFEXITED(status_actual));
// 	assert(WIFSIGNALED(status_expect) == WIFSIGNALED(status_actual));
// 	if (WIFEXITED(status_expect))
// 	{
// 		expect = strnstr(haystack, needle, len);
// 		actual = ft_strnstr(haystack, needle, len);
// 		printf("  %s：expect\n", expect);
// 		printf("  %s：actual\n", actual);
// 		if (expect == NULL &&  actual == NULL)
// 			return ;
// 		if (expect == NULL || actual == NULL)
// 			assert(0);
// 		assert(!strncmp(expect, actual,len));
// 	}
// 	else
// 	{
// 		printf(" Sig Abort \n");
// 		printf(" WTERMSIG:%d\n",WTERMSIG(status_actual));
// 	}
// }


// void	testmain_strnstr(void)
// {
// 	char *s1 = strdup("2");
// 	char *s2 = strdup("2");

// 	my_test_strnstr(s1,s2,3);
// 	my_test_strnstr(s1,s2,2);
// 	my_test_strnstr(s1,s2,1);
// 	my_test_strnstr(s1,s2,0);
// 	my_test_strnstr(s1,NULL,0);
// 	my_test_strnstr(NULL,s2,0);
// 	my_test_strnstr(NULL,NULL,0);
// 	my_test_strnstr(s1,NULL,1);
// 	my_test_strnstr(NULL,s2,1);
// 	my_test_strnstr(NULL,NULL,1);
// 	my_test_strnstr(s1,NULL,2);
// 	my_test_strnstr(NULL,s2,2);
// 	my_test_strnstr(NULL,NULL,2);
// 	my_test_strnstr(s1,NULL,3);
// 	my_test_strnstr(NULL,s2,3);
// 	my_test_strnstr(NULL,NULL,3);
// 	my_test_strnstr("abbbcdefg", "bbc", 1);
// 	my_test_strnstr("abbbcdefg", "bbc", 5);
// 	my_test_strnstr("abbbcdefg", "bbc", 100);
// 	my_test_strnstr("ab", "abcdefgh", 1);
// 	my_test_strnstr("ab", "abcdefgh", 5);
// 	my_test_strnstr("ab", "abcdefgh", 100);
// 	free(s1);
// 	free(s2);
// }


int	main(void)
{
	testmain_memmove();
	testmain_strlcat();
	testmain_strlcpy();
	// testmain_strnstr();

	if (system("leaks -q a.out > /dev/null"))
		system("leaks -q a.out");
	return (0);
}
