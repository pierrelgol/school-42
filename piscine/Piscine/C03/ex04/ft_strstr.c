/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:17:20 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/08 21:17:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*pto;
	char	*psrc;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		pto = to_find;
		psrc = str;
		while (*psrc == *pto)
		{
			if (*(pto + 1) == '\0' && *psrc == *pto)
				return (str);
			++pto;
			++psrc;
		}
		++str;
	}
	return ((void *)0);
}
// #include <assert.h>

// void test_normal(void)
// {
// 	char search[] = "Hello World!";
// 	char searching[] = "World";
// 	char *response;

// 	response = ft_strstr(search, searching);
// 	assert(*response == 'W');
// }

// void test_false(void)
// {
// 	char search[] = "Hello World!";
// 	char searching[] = "Worle";
// 	char *response;

// 	response = ft_strstr(search, searching);
// 	assert(response == (void *)0);
// }

// void test_false1(void)
// {
// 	char search[] = "Hello World!";
// 	char searching[] = "";
// 	char *response;

// 	response = ft_strstr(search, searching);
// 	assert(*response == 'H');
// }

// int main(void)
// {
// 	test_normal();
// 	__builtin_printf("Test normal --> Passed\n");
// 	test_false();
// 	__builtin_printf("Test false  --> Passed\n");
// 	test_false1();
// 	__builtin_printf("Test flase1 --> Passed\n");

// 	return (0);
// }