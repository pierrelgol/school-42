/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:24:26 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/08 21:24:29 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	char	*pstr;

	if (str != (void *)0)
	{
		pstr = str;
		while (*pstr)
			++pstr;
		return (pstr - str);
	}
	return (0);
}
// #include <assert.h>

// void test_normal(void)
// {
// 	char test[] = "Hello World";
// 	int ret = ft_strlen(test);
// 	assert(ret == 11);
// }

// void test_empty(void)
// {
// 	char test[] = "";
// 	int ret = ft_strlen(test);
// 	assert(ret == 0);
// }

// void test_null(void)
// {
// 	int ret = ft_strlen((void *)0);
// 	assert(ret == 0);
// }

// int main(void)
// {
// 	test_normal();
// 	__builtin_printf("test normal --> passed\n");
// 	test_empty();
// 	__builtin_printf("test empty --> passed\n");
// 	test_null();
// 	__builtin_printf("test null --> passed\n");
// 	return (0);
// }