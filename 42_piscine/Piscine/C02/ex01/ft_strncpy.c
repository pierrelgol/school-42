/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:08:57 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/08 12:09:04 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	if (dest != (void *)0 && src != (void *)0)
	{
		i = 0;
		while (*src && i < n)
		{
			dest[i] = *src++;
			i++;
		}
		while (i < n)
			dest[i++] = '\0';
	}
	return (dest);
}
// #include <stdio.h>
// #include <string.h>
// #include <assert.h>

// #define SIZE 13

// void test_basic(void)
// {
// 	char str[]      = "Hello World!";	
// 	char dest[SIZE] = {0};
// 	ft_strncpy(dest, str, SIZE);
// 	assert(strcmp(dest, str) == 0);
// }

// void test_empty(void)
// {
// 	char str[] = "";
// 	char dest[] = "";
// 	ft_strncpy(dest, str,0);
// 	assert(strcmp(dest, str) == 0);
// }

// int main(void)
// {
// 	test_basic();
// 	printf("Test Basic --> Passed\n");
// 	test_empty();
// 	printf("Test Empty --> Passed\n");

// 	return (0);
// }