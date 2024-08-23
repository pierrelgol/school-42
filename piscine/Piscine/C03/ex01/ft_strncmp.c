/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:13:27 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/08 21:13:38 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	if (n > 0)
	{
		while (*ps1 && *ps1 == *ps2 && --n)
		{
			++ps1;
			++ps2;
		}
		return (*ps1 - *ps2);
	}
	return (0);
}
// #include <assert.h>

// void test_equal(void)
// {
// 	int value = ft_strncmp("Hello", "Hello", 5);
// 	assert(value == 0);
// }

// void test_diff_neg(void)
// {
// 	int value = ft_strncmp("Hello", "Hello1", 6);
// 	assert(value < 0);
// }

// void test_diff_pos(void)
// {
// 	int value = ft_strncmp("Hello1", "Hello", 6);
// 	assert(value > 0);
// }

// void test_empty(void)
// {
// 	int value = ft_strncmp("", "", 0);
// 	assert(value == 0);
// }

// void test_null(void)
// {
// 	int value = ft_strncmp((void *)0, (void *)0, 0);
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
