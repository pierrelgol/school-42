/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:58:43 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/08 21:12:52 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	if (s1 != (void *)0 && s2 != (void *)0)
	{
		while (*s1 && *s1 == *s2)
		{
			++s1;
			++s2;
		}
		return (*s1 - *s2);
	}
	return (0);
}
// #include <assert.h>

// void test_equal(void)
// {
// 	int value = ft_strcmp("Hello", "Hello");
// 	assert(value == 0);
// }

// void test_diff_neg(void)
// {
// 	int value = ft_strcmp("Hello", "Hello1");
// 	assert(value < 0);
// }

// void test_diff_pos(void)
// {
// 	int value = ft_strcmp("Hello1", "Hello");
// 	assert(value > 0);
// }

// void test_empty(void)
// {
// 	int value = ft_strcmp("", "");
// 	assert(value == 0);
// }

// void test_null(void)
// {
// 	int value = ft_strcmp((void *)0, (void *)0);
// 	assert(value == 0);
// }

// int	main(void)
// {
// 	test_equal();
// 	__builtin_printf("Test equal -->    Passed\n");
// 	test_diff_neg();
// 	__builtin_printf("Test diff neg --> Passed\n");
// 	test_diff_pos();
// 	__builtin_printf("Test diff pos --> Passed\n");
// 	test_empty();
// 	__builtin_printf("Test empty -->    Passed\n");
// 	test_null();
// 	__builtin_printf("Test null -->     Passed\n");

// 	return (0);
// }