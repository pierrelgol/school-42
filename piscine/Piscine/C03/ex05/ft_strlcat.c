/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:19:04 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/11 09:14:37 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char *str)
{
	char	*ps;

	if (str != (void *)0)
	{
		ps = str;
		while (*ps)
			++ps;
		return (ps - str);
	}
	return (0);
}

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	smax;
	unsigned int	dlen;

	i = 0;
	dlen = ft_strlen(dst);
	smax = (size - 1) - dlen;
	if (dlen != 0 && size != 0 && size > dlen)
	{
		while (i < smax && src[i])
		{
			dst[dlen + i] = src[i];
			++i;
		}
		dst[dlen + i] = '\0';
	}
	return (dlen + i);
}
// #include <assert.h>
// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>

// void test_basic(void)
// {
// 	char src[] = " World!";
// 	char dest[14] = "Hello";
// 	int value;

// 	value = ft_strlcat(dest, src, sizeof(dest));
// 	__builtin_printf("value = %d | dest = %s\n",value,dest);
// 	assert(strcmp(dest, "Hello World!") == 0 && "Basic test failed");
// 	assert(value == 12);
// }

// void test_empty(void)
// {
// 	char src[] = "";
// 	char dest[] = "";
// 	int value;

// 	value = ft_strlcat(dest, src, sizeof(dest));
// 	__builtin_printf("value = %d | dest = %s\n",value,dest);
// 	assert(strcmp(dest, "") == 0);
// 	assert(value == 0);
// }

// void test_small(void)
// {
// 	char src[] = " This is very long string to test";
// 	char dest[1] = "";
// 	int value;
// 	value = ft_strlcat(dest, src, 20);
// 	__builtin_printf("value = %d, | dest = %s\n",value, dest);
// 	assert(value == 0);
// }

// int main(void)
// {

// 	test_basic();
// 	test_empty();
// 	test_small();
// 	return (0);
// }