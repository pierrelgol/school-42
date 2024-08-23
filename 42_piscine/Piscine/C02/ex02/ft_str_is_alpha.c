/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:39:59 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/08 12:09:29 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	if (!str || *str == '\0')
		return (1);
	while ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}
// #include <stdio.h>
// #include <assert.h>
// #include <string.h>

// void test_good(void)
// {
// 	char good[] = "abcdefghijklmnopqrstuvwxyz";
// 	int ret = ft_str_is_alpha(good);
// 	assert(ret == 1);
// }

// void test_empty(void)
// {
// 	char good[] = "";
// 	int ret = ft_str_is_alpha(good);
// 	assert(ret == 1);
// }

// void test_almost_good(void)
// {
// 	char almost_good[] = "abcdefghijklmnopqrstuvwxyz1";
// 	int ret = ft_str_is_alpha(almost_good);
// 	assert(ret == 0);
// }

// void test_certainly_not_good(void)
// {
// 	char certainly_not_good[] = "0abcdefghijklmnopqrstuvwxyz1";
// 	int ret = ft_str_is_alpha(certainly_not_good);
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