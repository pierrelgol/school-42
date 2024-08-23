/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:29:05 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/22 13:29:06 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

bool	pipex_is_valid_proc(t_process *proc)
{
	if (!proc->exec_path)
		return (false);
	if (access(proc->exec_path, X_OK) == -1)
		return (false);
	return (true);
}

void	pipex_second_child_process(t_process *proc)
{
	proc->outfile = pipex_file_open(proc->argv[proc->argc - 1], "w");
	proc->exec_argv = pipex_split(proc->argv[proc->argc - 2], " ");
	proc->exec_path = pipex_get_exe_path(proc, proc->exec_argv[0]);
	if (!pipex_is_valid_proc(proc) || proc->outfile == -1)
	{
		if (!string_bsearch(proc->exec_argv[0], '/'))
			memory_dealloc(proc->exec_path);
		pipex_close_pipes(proc);
		pipex_split_destroy(proc->exec_argv);
		pipex_error_and_die("error: no such file or directory\n", 1);
	}
	pipex_outfile_pipes(proc);
	pipex_close_pipes(proc);
	if (execve(proc->exec_path, proc->exec_argv, proc->envp) == -1)
	{
		if (!string_bsearch(proc->exec_argv[0], '/'))
			memory_dealloc(proc->exec_path);
		pipex_split_destroy(proc->exec_argv);
		pipex_error_and_die("error: command not found \n", 127);
	}
}

void	pipex_first_child_process(t_process *proc)
{
	proc->infile = pipex_file_open(proc->argv[1], "r");
	proc->exec_argv = pipex_split(proc->argv[2], " ");
	proc->exec_path = pipex_get_exe_path(proc, proc->exec_argv[0]);
	if (!pipex_is_valid_proc(proc) || proc->infile == -1)
	{
		if (!string_bsearch(proc->exec_argv[0], '/'))
			memory_dealloc(proc->exec_path);
		pipex_close_pipes(proc);
		pipex_split_destroy(proc->exec_argv);
		pipex_error_and_die("error: no such file or directory\n", 1);
	}
	pipex_infile_pipes(proc);
	pipex_close_pipes(proc);
	if (execve(proc->exec_path, proc->exec_argv, proc->envp) == -1)
	{
		if (!string_bsearch(proc->exec_argv[0], '/'))
			memory_dealloc(proc->exec_path);
		pipex_split_destroy(proc->exec_argv);
		pipex_error_and_die("error: command not found \n", 127);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_process	proc;
	pid_t		id;

	if (argc < 5)
		pipex_error_and_die("Error : argument count incorrect\n", 2);
	if (pipe(proc.pipes) == -1)
		pipex_perror_and_die(1);
	proc.argc = argc;
	proc.argv = argv;
	proc.envp = envp;
	proc.paths = pipex_get_env_paths(envp);
	id = fork();
	if (!id)
		pipex_first_child_process(&proc);
	else
	{
		id = fork();
		if (!id)
			pipex_second_child_process(&proc);
	}
	pipex_close_pipes(&proc);
	while (wait(NULL) > 0)
		continue ;
	return (0);
}
