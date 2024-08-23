/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:16:59 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 16:17:01 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int32_t	g_signal;

void	signals_heredoc_handler(int32_t signal)
{
	(void)signal;
	printf("\n");
	g_signal = 1;
	close(STDIN_FILENO);
}

void	signals_ctrl_handler(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signals_sigint_handler);
}

void	signals_sigint_handler(int signal)
{
	(void)signal;
	g_signal = 1;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signals_sigquit_handler(int signal)
{
	(void)signal;
}

void	signals_handle_eof(char *input)
{
	if (input == NULL)
	{
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
}

void	signals_setup_handlers(void)
{
	struct sigaction sa_int, sa_quit;
	sa_int.sa_handler = signals_sigint_handler;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa_int, NULL);
	sa_quit.sa_handler = signals_sigquit_handler;
	sigemptyset(&sa_quit.sa_mask);
	sa_quit.sa_flags = 0;
	sigaction(SIGQUIT, &sa_quit, NULL);
}

void	signal_init(void)
{
	signal(SIGINT, signals_sigint_handler);
	signal(SIGQUIT, signals_sigquit_handler);
	signals_setup_handlers();
}
