/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:27:43 by yejinkim          #+#    #+#             */
/*   Updated: 2023/06/27 23:04:21 by daheepark        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start_dir_NS(t_info *info)
{
	if (info->start_dir == 'N')
	{
		info->dir_x = -1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = 0.66;
	}
	else if (info->start_dir == 'S')
	{
		info->dir_x = 1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = -0.66;
	}
}

void	start_dir_EW(t_info *info)
{
	if (info->start_dir == 'E')
	{
		info->dir_x = 0.0;
		info->dir_y = 1.0;
		info->plane_x = 0.66;
		info->plane_y = 0.0;
	}
	else if (info->start_dir == 'W')
	{
		info->dir_x = 0.0;
		info->dir_y = -1.0;
		info->plane_x = -0.66;
		info->plane_y = 0.0;
	}
}

void	set_info(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "mlx 42");
	info->movespeed = 0.15;
	info->rotspeed = 0.1;
	if (info->start_dir == 'N' || info->start_dir == 'S')
		start_dir_NS(info);
	else if (info->start_dir == 'W' || info->start_dir == 'E')
		start_dir_EW(info);
}

void	raycasting(t_info *info)
{
	int	i;

	i = 0;
	draw_floor_ceil(info);
	while (i < WIDTH)
	{
		set_camera(info, &cam, i);
		draw_camera(info, &cam, i);
		i++;
	}
	draw_map(info);	
}
