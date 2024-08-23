/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:12:34 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/22 15:12:34 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	pipex_error(char *message)
{
	uint64_t	len;

	len = string_length(message);
	write(2, message, len);
}

void	pipex_error_and_die(char *message, int err_code)
{
	uint64_t	len;

	len = string_length(message);
	write(2, message, len);
	exit(err_code);
}

void	pipex_perror(void)
{
	perror("error");
}

void	pipex_perror_and_die(int err_code)
{
	perror("error");
	exit(err_code);
}
