/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:42:28 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/07 13:42:29 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	if (str != (void *)0)
	{
		i = 0;
		while (str[i])
		{
			if ((str[i] >= 'a' && str[i] <= 'z'))
				str[i] = (str[i] - 'a') + 'A';
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
// 	char good[] = "abcdefghijklmnopqrstuvwxyz";
// 	ft_strupcase(good);
// 	printf("%s\n",good);
// }

// void test_full(void)
// {
// 	char good[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// 	ft_strupcase(good);
// 	printf("%s\n",good);
// }

// void test_empty(void)
// {
// 	char good[] = "";
// 	ft_strupcase(good);
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