/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:43:55 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/13 10:43:59 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define N 10
#define TRUE 1
#define FALSE 0

int		ft_abs(int nb);
void	ft_print(int *board);
int		ft_check_solution(int col, int row, int *board);
void	ft_ten_queens(int col, int *board, int *solutions);
int		ft_ten_queens_puzzle(void);

int	ft_ten_queens_puzzle(void)
{
	int	board[N];
	int	index;
	int	solutions;

	index = 0;
	solutions = 0;
	while (index < N)
		board[index++] = -1;
	ft_ten_queens(0, board, &solutions);
	return (solutions);
}

void	ft_print(int *board)
{
	int	index;
	int	nb;

	index = 0;
	while (index < N)
	{
		nb = '0' + board[index++];
		write(1, &nb, 1);
	}
	write(1, &"\n", 1);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_check_solution(int col, int row, int *board)
{
	int	index;

	index = 0;
	while (index < col)
	{
		if (board[index] == row || ft_abs(col - index) == ft_abs(board[index]
				- row))
			return (FALSE);
		++index;
	}
	return (TRUE);
}

void	ft_ten_queens(int col, int *board, int *solutions)
{
	int	row;

	if (col == N)
	{
		*solutions += 1;
		ft_print(board);
		return ;
	}
	row = 0;
	while (row < N)
	{
		if (ft_check_solution(col, row, board) == TRUE)
		{
			board[col] = row;
			ft_ten_queens(col + 1, board, solutions);
			board[col] = -1;
		}
		++row;
	}
}
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n", ft_ten_queens_puzzle());
// 	return (0);
// }