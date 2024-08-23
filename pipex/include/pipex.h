/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:57:31 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/22 08:57:31 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "clib.h"
# include <assert.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

// int32_t	file_mode(char *mode)
// {
// 	if (mode[0] == 'r')
// 		return (O_RDONLY);
// 	if (mode[0] == 'w')
// 		return (O_WRONLY | O_CREAT | O_TRUNC);
// 	if (mode[0] == 'a')
// 		return (O_WRONLY | O_CREAT | O_APPEND);
// 	if (mode[0] == 'r' && mode[1] == '+')
// 		return (O_RDWR);
// 	if (mode[0] == 'w' && mode[1] == '+')
// 		return (O_RDWR | O_CREAT | O_TRUNC);
// 	if (mode[0] == 'a' && mode[1] == '+')
// 		return (O_RDWR | O_CREAT | O_APPEND);
// 	return (0);
// }

typedef struct s_process
{
	int		pipes[2];
	int		index;
	int		pid1;
	int		pid2;
	int		infile;
	int		outfile;
	int		argc;
	char	**argv;
	char	**envp;
	char	*paths;
	char	*exec_path;
	char	**exec_argv;

}			t_process;

char		*pipex_get_env_paths(char **envp);
char		*pipex_get_exe_path(t_process *proc, char *name);

// ************************************************************************* //
//                             Pipex Pipes                                   //
// ************************************************************************* //

void		pipex_infile_pipes(t_process *proc);
void		pipex_outfile_pipes(t_process *proc);
void		pipex_close_pipes(t_process *proc);

// ************************************************************************* //
//                             Pipex Error                                   //
// ************************************************************************* //
void		pipex_error(char *message);
void		pipex_error_and_die(char *message, int err_code);
void		pipex_perror(void);
void		pipex_perror_and_die(int err_code);

// ************************************************************************* //
//                             Pipex Utils                                   //
// ************************************************************************* //

char		*pipex_joins(char *str1, char *str2, char *str3);
char		**pipex_split(char *string, char *delim);
char		**pipex_split_destroy(char **split);
int			pipex_file_open(char *name, char *mode);

#endif
