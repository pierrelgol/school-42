/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:43:54 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/07 13:43:57 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	char	*pstr;

	pstr = str;
	while (*pstr)
		++pstr;
	return (pstr - str);
}

int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0 || *src == '\0')
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
// #include <stdio.h>
// #include <assert.h>
// #include <string.h>

// void test_basic(void)
// {
// 	char src[] = "abcdefghijklmnopqrstuvwxyz";
// 	char dest[27];
// 	int value = ft_strlcpy(dest, src, 26);
// 	printf("%s | copyied = %d\n",dest,value);
// 	assert(value == 26);
// }

// void test_too_small(void)
// {
// 	char src[] = "abcdefghijklmnopqrstuvwxyz";
// 	char dest[20];
// 	int value = ft_strlcpy(dest, src, 20);
// 	printf("%s | copyied = %d\n",dest,value);
// 	assert(value == 26);
// }

// void test_too_empty(void)
// {
// 	char src[] = "";
// 	char dest[20];
// 	int value = ft_strlcpy(dest, src, 20);
// 	printf("%s | copyied = %d\n",dest,value);
// 	assert(value == 0);
// }

// void test_size_too_small(void)
// {
// 	char src[] = "abcdefghijklmnopqrs";
// 	char dest[20];
// 	int value = ft_strlcpy(dest, src, 0);
// 	printf("%s | copyied = %d\n",dest,value);
// 	assert(value == 19);
// }

// int main(void)
// {
// 	test_basic();
// 	printf("Test good --> passed\n");
// 	test_too_small();
// 	printf("Test too_small --> passed\n");
// 	test_too_empty();
// 	printf("Test too_empty --> passed\n");
// 	test_size_too_small();
// 	printf("Test size_too_small --> passed\n");

// 	return (0);
// }