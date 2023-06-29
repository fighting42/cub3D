/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:27:43 by yejinkim          #+#    #+#             */
/*   Updated: 2023/06/29 17:30:30 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	wall_x_or_y(t_info *info, t_mapcamera *mapcam)
{
	while (mapcam->hit == 0)
	{
		if (mapcam->sidedist_x < mapcam->sidedist_y)
		{
			mapcam->sidedist_x += mapcam->deltadist_x;
			mapcam->map_x += mapcam->step_x;
			mapcam->side = 0;
		}
		else
		{
			mapcam->sidedist_y += mapcam->deltadist_y;
			mapcam->map_y += mapcam->step_y;
			mapcam->side = 1;
		}
		if (info->map[mapcam->map_x][mapcam->map_y] == '1')
			mapcam->hit = 1;
	}
	if (mapcam->side == 0) //x면과 충돌
		mapcam->perwalldist = (mapcam->map_x - info->pos_x
				+ (1 - mapcam->step_x) / 2) / mapcam->raydir_x;
	else //y면과 충돌
		mapcam->perwalldist = (mapcam->map_y - info->pos_y
				+ (1 - mapcam->step_y) / 2) / mapcam->raydir_y;
}

void	set_moving_dir(t_info *info, t_mapcamera *mapcam)
{
	if (mapcam->raydir_x > 0)
	{
		mapcam->step_x = 1;
		mapcam->sidedist_x = (mapcam->map_x + 1.0 - info->pos_x) \
							* mapcam->deltadist_x;
	}
	else
	{
		mapcam->step_x = -1;
		mapcam->sidedist_x = (info->pos_x - mapcam->map_x) \
							* mapcam->deltadist_x;
	}
	if (mapcam->raydir_y > 0)
	{
		mapcam->step_y = 1;
		mapcam->sidedist_y = (mapcam->map_y + 1.0 - info->pos_y) \
							* mapcam->deltadist_y;
	}
	else
	{
		mapcam->step_y = -1;
		mapcam->sidedist_y = (info->pos_y - mapcam->map_y) \
							* mapcam->deltadist_y;
	}
}

void	set_mapcamera(t_info *info, t_mapcamera *mapcam, int i)
{
	mapcam->camera_x = 2 * i / (double)WIDTH - 1;
	mapcam->map_x = (int)info->pos_x;
	mapcam->map_y = (int)info->pos_y;
	mapcam->deltadist_x = fabs(1 / mapcam->raydir_x);
	mapcam->deltadist_y = fabs(1 / mapcam->raydir_y);
	mapcam->raydir_x = info->dir_x + mapcam->camera_x * info->plane_x;
	mapcam->raydir_y = info->dir_y + mapcam->camera_x * info->plane_y;
	set_moving_dir(info, mapcam);
	mapcam->hit = 0;
	wall_x_or_y(info, mapcam);
	mapcam->line_height = HEIGHT / mapcam->perwalldist;
	mapcam->start_point = (HEIGHT / 2) - (mapcam->line_height / 2);
	if (mapcam->start_point < 0)
		mapcam->start_point = 0;
	mapcam->end_point = (HEIGHT / 2) + (mapcam->line_height / 2);
}

int	raycasting(t_info *info)
{
	int			i;
	t_mapcamera	mapcam;

	i = 0;
	draw_floor_ceil(info);
	while (i < WIDTH)
	{
		set_mapcamera(info, &mapcam, i);
		draw_mapcamera(info, &mapcam, i);
		i++;
	}
	draw_map(info);
	return (0);
}
