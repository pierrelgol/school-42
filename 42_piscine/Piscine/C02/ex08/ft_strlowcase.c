/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:42:48 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/07 13:42:49 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	if (str != (void *)0)
	{
		i = 0;
		while (str[i])
		{
			if ((str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = (str[i] - 'A') + 'a';
			++i;
		}
		return (str);
	}
	return ((void *)0);
}
// #include <stdio.h>
// #include <assert.h>
// #include <string.h>

// void test_good(void)
// {
// 	char good[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// 	ft_strlowcase(good);
// 	printf("%s\n",good);
// }

// void test_full(void)
// {
// 	char good[] = "abcdefghijklmnopqrstuvwxyz";
// 	ft_strlowcase(good);
// 	printf("%s\n",good);
// }

// void test_empty(void)
// {
// 	char good[] = "";
// 	ft_strlowcase(good);
// 	printf("%s\n",good);
// }

// int main(void)
// {
// 	test_good();
// 	printf("Test good --> passed\n");
// 	test_empty();
// 	printf("Test empty --> passed\n");
// 	test_full();
// 	printf("Test empty --> passed\n");

// 	return (0);
// }