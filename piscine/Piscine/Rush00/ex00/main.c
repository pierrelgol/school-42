/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:53:21 by melmarti          #+#    #+#             */
/*   Updated: 2023/09/10 17:03:35 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int y, int x);
char	rush_get_char(int x, int y, int x_max, int y_max);
void	ft_putchar(char ch);

int	main(void)
{
	rush(5, 5);
	return (0);
}
