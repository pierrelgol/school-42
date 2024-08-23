/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:11:32 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/17 20:11:33 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_MAP_H
# define R01_MAP_H
# include "r01_core.h"

t_map	*map_init(t_args *in);
bool	map_map(t_map *self, t_args *in);
t_map	*map_dispose(t_map *self);

#endif
