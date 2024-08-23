/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_is_alnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:28:13 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/30 21:28:13 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

int	char_is_alnum(int ch)
{
	return (char_is_alpha(ch) || char_is_digit(ch));
}
