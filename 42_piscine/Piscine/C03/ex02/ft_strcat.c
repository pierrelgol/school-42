/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:14:50 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/08 21:19:30 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		++i;
	while (*src)
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

// 	ft_strcat(dest, src);
// 	assert(strcmp(dest, "Hello World!") == 0);
// }

// void test_empty(void)
// {
// 	char src[] = "";
// 	char dest[1] = "";

// 	ft_strcat(dest, src);
// 	assert(strcmp(dest, "") == 0);
// }

// int main(void)
// {
// 	test_basic();
// 	__builtin_printf("Test basic --> Passed\n");
// 	test_empty();
// 	__builtin_printf("Test empty --> Passed\n");
// 	return (0);
// }