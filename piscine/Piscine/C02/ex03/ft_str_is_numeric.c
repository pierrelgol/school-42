/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:40:19 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/07 13:40:20 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	if (!str || *str == '\0')
		return (1);
	while (*str >= '0' && *str <= '9')
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
// 	char good[] = "11111111111111111111111111";
// 	int ret = ft_str_is_numeric(good);
// 	assert(ret == 1);
// }

// void test_empty(void)
// {
// 	char good[] = "";
// 	int ret = ft_str_is_numeric(good);
// 	assert(ret == 1);
// }

// void test_almost_good(void)
// {
// 	char almost_good[] = "111111111111111111111111111A";
// 	int ret = ft_str_is_numeric(almost_good);
// 	assert(ret == 0);
// }

// void test_certainly_not_good(void)
// {
// 	char certainly_not_good[] = "A1111111111111111111111111111";
// 	int ret = ft_str_is_numeric(certainly_not_good);
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