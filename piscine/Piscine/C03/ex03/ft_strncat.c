/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:23:01 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/08 12:23:09 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;

	i = 0;
	while (dest[i])
		++i;
	while (*src && nb--)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}
// #include <assert.h>
// #include <string.h>

// void test_basic(void)
// {
// 	char src[] = " World!";
// 	char dest[14] = "Hello";

// 	ft_strncat(dest, src, 13);
// 	assert(strcmp(dest, "Hello World!") == 0);
// }

// void test_empty(void)
// {
// 	char src[] = "";
// 	char dest[1] = "";

// 	ft_strncat(dest, src, 1);
// 	assert(strcmp(dest, "") == 0);
// }

// void test_small(void)
// {
// 	char src[] = " World!";
// 	char dest[] = "H";

// 	ft_strncat(dest, src, 0);
// 	assert(strcmp(dest, "H") == 0);
// }

// int main(void)
// {
// 	test_basic();
// 	__builtin_printf("Test basic --> Passed\n");
// 	test_empty();
// 	__builtin_printf("Test empty --> Passed\n");
// 	test_small();
// 	__builtin_printf("Test small --> Passed\n");
// 	return (0);
// }