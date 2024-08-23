/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_debug.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:52:56 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/23 13:52:58 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_DEBUG_H
#define NUM_DEBUG_H

#include "num_base.h"
#include "num_print.h"
#include "num_helpers.h"

void	debug_file(t_file *file);
void	debug_stack(t_stack *stack);
void	debug_slice(t_slice *slice);

#endif
