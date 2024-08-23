/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:45:28 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/07 13:45:31 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(unsigned long int number, unsigned int size)
{
	if (size == 0)
		return ;
	ft_print_hex(number / 16, size - 1);
	write(1, &"0123456789abcdef"[number % 16], 1);
}

void	ft_print_content(char *at, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (*(at + i) >= 32 && *(at + i) <= 126)
			write(1, (at + i), 1);
		else
			write(1, &".", 1);
		++i;
	}
	write(1, &"\n", 1);
}

void	ft_print_16(char *at, unsigned int size)
{
	unsigned int	i;

	i = 0;
	ft_print_hex((unsigned long int)at, 16);
	write(1, &": ", 2);
	while (i < 16)
	{
		if ((i + 2) <= size)
		{
			ft_print_hex((unsigned long int)*(at + i), 2);
			ft_print_hex((unsigned long int)*(at + i + 1), 2);
			write(1, " ", 1);
		}
		else
		{
			write(1, "  ", 2);
			write(1, "  ", 2);
			write(1, " ", 1);
		}
		i += 2;
	}
	ft_print_content(at, size);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*current;
	char	*end;

	end = (char *)addr + size;
	current = (char *)addr;
	while ((char *)current < end && size != 0)
	{
		if (size >= 16)
			ft_print_16(current, 16);
		else
			ft_print_16(current, size);
		size -= 16;
		current += 16;
	}
	return (addr);
}
 #include <stdio.h>
 #include <string.h>
 int main(int argc, char **argv)
 {
 	// char test[] = "Bonjour les aminches\n\n\nc\n est fou\ntout\nce qu on peut faire avec\n\n\nprint_memory\n\n\n\nlol\nlol\n ";
	if (argc == 2)
	 	ft_print_memory(argv[1], strlen(argv[1]));
 	return(0);
 }