/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expression_is_start_token.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:02:31 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 20:02:31 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

bool expression_is_start_token(t_expression_kind expr_kind, t_token_kind tok_kind)
{
	if (expr_kind == EXPR_COMMAND)
		return (tok_kind == KIND_CMD || tok_kind == KIND_PATH || tok_kind == KIND_ID);
	if (expr_kind == EXPR_BUILTIN)
		return (tok_kind == KIND_BLTN || tok_kind == KIND_ID);
	if (expr_kind == EXPR_ASSIGNMENT)
		return (tok_kind == KIND_EQL || tok_kind == KIND_VAR || tok_kind == KIND_ID);
	if (expr_kind == EXPR_PIPE)
		return (tok_kind == KIND_PIPE);
	if (expr_kind == EXPR_LEFT_REDIR)
		return (tok_kind == KIND_LRDIR);
	if (expr_kind == EXPR_RIGHT_REDIR)
		return (tok_kind == KIND_RRDIR);
	if (expr_kind == EXPR_APPEND)
		return (tok_kind == KIND_APPEND);
	if (expr_kind == EXPR_HERE_DOC)
		return (tok_kind == KIND_HERE_DOC);
	return (false);
}
