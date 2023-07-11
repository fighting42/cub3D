/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:40:04 by daheepark         #+#    #+#             */
/*   Updated: 2023/07/11 15:47:01 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start_dir_ns(t_info *info)
{
	if (info->start_dir == 'N')
	{
		info->dir_x = 0.0;
		info->dir_y = -1.0;
		info->plane_x = 0.66;
		info->plane_y = 0.0;
	}
	else if (info->start_dir == 'S')
	{
		info->dir_x = 0.0;
		info->dir_y = 1.0;
		info->plane_x = -0.66;
		info->plane_y = 0.0;
	}
}

void	start_dir_ew(t_info *info)
{
	if (info->start_dir == 'E')
	{
		info->dir_x = 1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = 0.66;
	}
	else if (info->start_dir == 'W')
	{
		info->dir_x = -1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = -0.66;
	}
}

void	init_buf(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	set_info(t_info *info)
{
	info->mlx = mlx_init();
	info->movespeed = 0.15;
	info->rotspeed = 0.1;
	init_buf(info);
	set_texture(info);
	if (info->start_dir == 'N' || info->start_dir == 'S')
		start_dir_ns(info);
	else if (info->start_dir == 'W' || info->start_dir == 'E')
		start_dir_ew(info);
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "cub3D");
	info->img[0].img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->img[0].data = (int *)mlx_get_data_addr(info->img[0].img, \
			&info->img[0].bpp, &info->img[0].line_size, &info->img[0].endian);
}
