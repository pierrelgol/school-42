/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_args.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:11:18 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/17 20:11:19 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_ARGS_H
# define R01_ARGS_H
# include "r01_core.h"

t_args	*args_init(char *args);
bool	args_parse(t_args *self, char *args);
bool	args_fill(t_args *self, char *args);
t_args	*args_dispose(t_args *self);

#endif
