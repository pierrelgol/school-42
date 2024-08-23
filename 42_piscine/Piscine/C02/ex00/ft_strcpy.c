/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:04:34 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/08 12:04:38 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	if (dest != (void *)0 && src != (void *)0)
	{
		i = 0;
		while (*src)
			dest[i++] = *src++;
		dest[i] = '\0';
	}
	return (dest);
}
// #include <stdio.h>
// #include <assert.h>
// #include <string.h>

// void test_simple(void)
// {
// 	char str[] = "Hello World!";
// 	char dest[13];
// 	ft_strcpy(dest, str);
// 	assert(strcmp(str, dest) == 0);
// }

// void test_empty(void)
// {
// 	char str[] = "";
// 	char dest[] = "";
// 	ft_strcpy(dest, str);
// 	assert(strcmp(str, dest) == 0);
// }

// // void test_toosmall(void)
// // {
// // 	char str[] = "This is going to crash";
// // 	char dest[1] = "";
// // 	ft_strcpy(dest, str);
// // 	assert(strcmp(str, dest) == 0);
// // }

// int main(void)
// {
// 	test_simple();
// 	printf("Test simple --> Passed\n");
// 	test_empty();
// 	printf("Test empty --> Passed\n");
// 	// test_toosmall();
// 	// printf("Test simple --> Passed\n");

// 	return (0);
// }
