/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:43:32 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/07 13:43:34 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline int	ft_is_alnum(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static inline int	ft_tolower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return ((ch - 'A') + 'a');
	return (ch);
}

static inline int	ft_toupper(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return ((ch - 'a') + 'A');
	return (ch);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	searching_word;

	if (str == (void *)0)
		return ((void *)0);
	i = 0;
	searching_word = 1;
	while (str[i])
	{
		if (searching_word == 1 && ft_is_alnum(str[i]))
		{
			searching_word = 0;
			str[i] = ft_toupper(str[i]);
			++i;
			while (str[i] && searching_word == 0)
			{
				str[i] = ft_tolower(str[i]);
				if (ft_is_alnum(str[i++]) == 0)
					searching_word = 1;
			}
		}
		else
			++i;
	}
	return (str);
}
// #include <stdio.h>
// #include <assert.h>
// #include <string.h>

// void test_good(void)
// {
// 	char good[] = "this sentence need to have a more capitalised word";
// 	ft_strcapitalize(good);
// 	printf("%s\n",good);
// }

// void test_full(void)
// {
// 	char good[] = "This Sentence Need To Have A More Capitalised Word";
// 	ft_strcapitalize(good);
// 	printf("%s\n",good);
// }

// void test_empty(void)
// {
// 	char good[] = "";
// 	ft_strcapitalize(good);
// 	printf("%s\n",good);
// }

// void test_plus(void)
// {
// 	char *good = (void *)0;
// 	ft_strcapitalize(good);
// }

// int main(void)
// {
// 	test_good();
// 	printf("Test good --> passed\n");
// 	test_empty();
// 	printf("Test empty --> passed\n");
// 	test_full();
// 	printf("Test empty --> passed\n");
// 	test_plus();
// 	printf("Test empty --> passed\n");

// 	return (0);
// }