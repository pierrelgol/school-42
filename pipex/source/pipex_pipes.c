/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:12:01 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/22 15:12:01 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	pipex_infile_pipes(t_process *proc)
{
	dup2(proc->pipes[1], 1);
	dup2(proc->infile, 0);
	close(proc->infile);
	pipex_close_pipes(proc);
}

void	pipex_outfile_pipes(t_process *proc)
{
	dup2(proc->pipes[0], 0);
	dup2(proc->outfile, 1);
	close(proc->outfile);
	pipex_close_pipes(proc);
}

void	pipex_close_pipes(t_process *proc)
{
	close(proc->pipes[0]);
	close(proc->pipes[1]);
}
