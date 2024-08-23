/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:33:19 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 13:34:56 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*print_kind(t_token_kind kind)
{
	if (kind == KIND_NO_KIND)
		return ("NO_KIND");
	if (kind == KIND_ERROR)
		return ("ERROR");
	if (kind == KIND_SPC)
		return ("SPC");
	if (kind == KIND_SLASH)
		return ("SLASH");
	if (kind == KIND_APPEND)
		return ("APPEND");
	if (kind == KIND_ARG)
		return ("ARG");
	if (kind == KIND_BLTN)
		return ("BLTN");
	if (kind == KIND_CMD)
		return ("CMD");
	if (kind == KIND_DQUOTE)
		return ("DQUOTE");
	if (kind == KIND_EQL)
		return ("EQL");
	if (kind == KIND_FILE)
		return ("FILE");
	if (kind == KIND_HERE_DOC)
		return ("HERE_DOC");
	if (kind == KIND_HERE_DOC_DELIM)
		return ("HERE_DOC_DELIM");
	if (kind == KIND_ID)
		return ("ID");
	if (kind == KIND_LRDIR)
		return ("LRDIR");
	if (kind == KIND_PATH)
		return ("PATH");
	if (kind == KIND_PIPE)
		return ("PIPE");
	if (kind == KIND_QUOTE)
		return ("QUOTE");
	if (kind == KIND_RRDIR)
		return ("RRDIR");
	if (kind == KIND_UNKOWN)
		return ("UNKOWN");
	if (kind == KIND_VAR)
		return ("VAR");
	if (kind == KIND_END_TOKEN)
		return ("END_TOKEN");
	return ("UNKNOWN");
}

void	token_print(t_token *token)
{
	printf("[kind: %s | str : %s]\n", print_kind(token->kind), token->string);
}
