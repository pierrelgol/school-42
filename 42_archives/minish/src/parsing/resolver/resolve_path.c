/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:52:44 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/07 09:52:44 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	resolve_path(t_resolver *self, t_token *token)
{
	(void)self;
	return (access(token_get_str(token), F_OK | R_OK | W_OK));
}
