/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:53:00 by melmarti          #+#    #+#             */
/*   Updated: 2023/09/10 17:06:36 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	rush_get_char(int x, int y, int x_max, int y_max);
void	ft_putchar(char ch);
int		ft_abs(int n);

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	rush(int y, int x)
{
	char	to_print;
	int		pos_x;
	int		pos_y;

	y = ft_abs(y);
	x = ft_abs(x);
	pos_x = 1;
	while (pos_x <= x)
	{
		pos_y = 1;
		while (pos_y <= y)
		{
			to_print = rush_get_char(pos_x, pos_y, x, y);
			ft_putchar(to_print);
			++pos_y;
		}
		ft_putchar('\n');
		++pos_x;
	}
}

char	rush_get_char(int x, int y, int x_max, int y_max)
{
	if (x == 1 && y == 1)
		return ('/');
	else if (x == 1 && y == y_max)
		return ('\\');
	else if (x == x_max && y == 1)
		return ('\\');
	else if (x == x_max && y == y_max)
		return ('/');
	else if (x == 1 && y > 1 && y < y_max)
		return ('*');
	else if (y == 1 && x > 1 && x < x_max)
		return ('*');
	else if (x == x_max && y > 1 && y < y_max)
		return ('*');
	else if (y == y_max && x > 1 && x < x_max)
		return ('*');
	return (' ');
}
