/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_concat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:38:34 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 13:38:35 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

char	*string_concat(char *dst, char *src, unsigned int n)
{
	string_copy(dst + string_length(dst), src, n);
	return (dst);
}
