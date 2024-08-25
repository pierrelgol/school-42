/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_debug_log.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:05:33 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 13:05:34 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"
#include <stdio.h>

void	smlx_instance_log(const t_smlx_instance *const self,
		const char *const label)
{
	printf("---------------- %s ----------------\n", label);
	if (!self)
	{
		fflush(stdout);
		return ;
	}
	printf("                                     \n");
	printf("struct s_mlx_instance           '%p' \n", self);
	printf("{                                    \n");
	printf("    t_smlx_handle *mlx;         '%p' \n", self->mlx);
	printf("    int32_t       height;       '%d' \n", self->height);
	printf("    int32_t       width;        '%d' \n", self->width);
	printf("                                     \n");
	printf("    t_smlx_handle *win;         '%p' \n", self->win);
	printf("    char          *title;       '%s' \n", self->title);
	printf("                                     \n");
	printf("    t_smlx_handle *img;         '%p' \n", self->img);
	printf("    int32_t       fid;          '%d' \n", self->fid);
	printf("    int32_t       bpp;          '%d' \n", self->bpp);
	printf("    int32_t       size;         '%d' \n", self->size);
	printf("    int32_t       endian;       '%d' \n", self->endian);
	printf("    uint8_t       *data;        '%p' \n", self->data);
	printf("                                     \n");
	printf("                                     \n");
	printf("    int64_t       render_ready; '%d' \n", self->render_ready);
	printf("    int64_t       time_last_ms; '%ld'\n", self->time_last_ms);
	printf("    int64_t       time_trgt_ms; '%ld'\n", self->time_trgt_ms);
	printf("    int64_t       time_prev_ms; '%ld'\n", self->time_prev_ms);
	printf("    int64_t       time_curr_ms; '%ld'\n", self->time_curr_ms);
	printf("    int64_t       time_delt_ms; '%ld'\n", self->time_delt_ms);
	printf("    int64_t       frame_countr; '%ld'\n", self->frame_counter);
	printf("    int64_t       frame_rendrd; '%ld'\n", self->frame_rendered);
	printf("                                     \n");
	printf("    int32_t       frame_buflvl; '%d' \n", self->frame_buffer_lvl);
	printf("}                                    \n");
	printf("                                     \n");
	fflush(stdout);
}
