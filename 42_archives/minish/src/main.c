/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:13:46 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 13:32:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "c-stacktrace.h"

int32_t	g_signal;

int32_t	main(int32_t argc, char **argv, char **envp)
{
	t_shell	*minishell;

	init_exceptions(argv[0]);
	minishell = shell_create(argc, argv, envp);
	setvbuf(stdout, NULL, _IONBF, 0);
	signal_init();
	// envmap_print_one(minishell->envmap, "PATH");
	while (shell_readline(minishell, "minishell $>"))
	{
		printf("%s\n", minishell->line);
		shell_process(minishell);
		shell_clear(minishell);
	}
	// minishell = shell_destroy(minishell);
	return (EXIT_SUCCESS);
}
