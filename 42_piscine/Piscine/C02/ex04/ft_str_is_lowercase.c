/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:41:22 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/07 13:41:25 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	if (str != (void *)0)
	{
		while (*str && (*str >= 'a' && *str <= 'z'))
			++str;
		if (*str == '\0')
			return (1);
	}
	return (0);
}
// #include <stdio.h>
// #include <assert.h>
// #include <string.h>

// void test_good(void)
// {
// 	char good[] = "abcdefghijklmnopqrstuvwxyz";
// 	int ret = ft_str_is_lowercase(good);
// 	assert(ret == 1);
// }

// void test_empty(void)
// {
// 	char good[] = "";
// 	int ret = ft_str_is_lowercase(good);
// 	assert(ret == 1);
// }

// void test_almost_good(void)
// {
// 	char almost_good[] = "abcdefghijklmnopqrstuvwxyz1";
// 	int ret = ft_str_is_lowercase(almost_good);
// 	assert(ret == 0);
// }

// void test_certainly_not_good(void)
// {
// 	char certainly_not_good[] = "0abcdefghijklmnopqrstuvwxyz1";
// 	int ret = ft_str_is_lowercase(certainly_not_good);
// 	assert(ret == 0);
// }

// int main(void)
// {
// 	test_good();
// 	printf("Test good --> passed\n");
// 	test_empty();
// 	printf("Test empty --> passed\n");
// 	test_almost_good();
// 	printf("Test almost_good --> passed\n");
// 	test_certainly_not_good();
// 	printf("Test certainly_not_good --> passed\n");

// 	return (0);
// }