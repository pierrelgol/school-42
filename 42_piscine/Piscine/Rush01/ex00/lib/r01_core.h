/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_core.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:11:25 by pollivie          #+#    #+#             */
/*   Updated: 2023/09/17 20:11:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_CORE_H
# define R01_CORE_H

# include <assert.h>
# include <iso646.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_args
{
	int		args_size;
	int		args_max;
	int		args_min;
	short	args_count;
	bool	args_valid;
	int		*inputs;

}			t_args;

typedef struct s_map
{
	int		map_dim;
	int		map_row;
	int		map_col;
	bool	map_valid;
	int		**map;
}			t_map;

#endif
