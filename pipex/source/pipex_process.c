/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:12:24 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/22 15:12:25 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*pipex_get_env_paths(char **envp)
{
	uint64_t	i;

	i = 0;
	while (string_search(envp[i], "PATH=", 5) == 0)
		++i;
	return (envp[i] + 5);
}

char	*pipex_get_exe_path(t_process *proc, char *name)
{
	char		**paths;
	char		*maybe_path;
	uint64_t	i;

	i = 0;
	paths = pipex_split(proc->paths, ":");
	while (paths[i])
	{
		maybe_path = pipex_joins(paths[i], "/", name);
		if (access(maybe_path, X_OK) == 0)
		{
			pipex_split_destroy(paths);
			return (maybe_path);
		}
		memory_dealloc(maybe_path);
		++i;
	}
	pipex_split_destroy(paths);
	return (name);
}
