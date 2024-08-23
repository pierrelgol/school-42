/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expression_is_terminal_token.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:01:53 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 20:01:54 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

bool expression_is_terminal_token(t_expression_kind expr_kind, t_token_kind tok_kind)
{
	if (expr_kind == EXPR_COMMAND || expr_kind == EXPR_BUILTIN || expr_kind == EXPR_ASSIGNMENT)
		return ( tok_kind == KIND_NO_KIND || tok_kind == KIND_ID || tok_kind == KIND_END_TOKEN || tok_kind == KIND_ARG);
	if (expr_kind == EXPR_PIPE)
		return (false);
	if (expr_kind == EXPR_LEFT_REDIR)
		return (tok_kind == KIND_FILE || tok_kind == KIND_PATH || tok_kind == KIND_ID || tok_kind == KIND_ARG);
	if (expr_kind == EXPR_RIGHT_REDIR)
		return (tok_kind == KIND_FILE || tok_kind == KIND_PATH || tok_kind == KIND_ID || tok_kind == KIND_ARG);
	if (expr_kind == EXPR_APPEND)
		return (tok_kind == KIND_FILE || tok_kind == KIND_ARG || tok_kind == KIND_ID);
	if (expr_kind == EXPR_HERE_DOC)
		return (tok_kind == KIND_ARG || tok_kind == KIND_ID);
	return (false);
}
