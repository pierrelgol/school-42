/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_readline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:12:00 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 16:12:00 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	shell_readline(t_shell *self, char *prompt)
{
	if (DEBUG)
	{
		if (++self->index < self->argc)
			self->line = string_clone(self->argv[self->index]);
		else
			self->line = NULL;
	}
	else
		self->line = readline(prompt);
	self->is_dirty = true;
	if (!self->line)
	{
		signals_handle_eof(self->line);
		shell_destroy(self);
		exit(EXIT_SUCCESS);
		return (false);
	}
	else
		add_history(self->line);
	return (true);
}
