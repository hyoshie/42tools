/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie </var/mail/hyoshie>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:51:26 by hyoshie           #+#    #+#             */
/*   Updated: 2021/11/15 00:51:34 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

int	ft_atoi(const char *ptr);

bool	compare(char *str)
{
	if (atoi(str) == ft_atoi(str))
		return (true);
	else
		return (false);
}

void	print(char *str)
{
	printf("%s\n", str);
	printf("rtn : (st)%d, (ft)%d\n", atoi(str), ft_atoi(str));
}

bool	test(char *str)
{
	//print(str);
	return compare(str);
}

/*
 * Check Over/Underflow
 * TEST_around_5_value
 * LONG_MAX=9223372036854775807
 * LONG_MAX=-9223372036854775808
*/
int	main(void)
{
	//LONGMAX_around 5
	assert(test("9223372036854775802"));
	assert(test("9223372036854775803"));
	assert(test("9223372036854775804"));
	assert(test("9223372036854775805"));
	assert(test("9223372036854775806"));
	assert(test("9223372036854775807"));//longmax
	assert(test("9223372036854775808"));
	assert(test("9223372036854775809"));
	assert(test("9223372036854775810"));
	assert(test("9223372036854775811"));
	assert(test("9223372036854775812"));
	//LONGMIN_around 5
	assert(test("-9223372036854775803"));
	assert(test("-9223372036854775804"));
	assert(test("-9223372036854775805"));
	assert(test("-9223372036854775806"));
	assert(test("-9223372036854775807"));
	assert(test("-9223372036854775808"));//longmin
	assert(test("-9223372036854775809"));
	assert(test("-9223372036854775810"));
	assert(test("-9223372036854775811"));
	assert(test("-9223372036854775812"));
	assert(test("-9223372036854775813"));
	//Congraturation
	printf("\x1b[32mCongraturation!!\x1b[m\n");
}

