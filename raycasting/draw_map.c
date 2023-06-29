/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:41:58 by daheepark         #+#    #+#             */
/*   Updated: 2023/06/29 18:07:36 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_ceil(t_info *info)
{
	int	i;
	int	j;

	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
			{
				info->buf[i][j] = info->data->floor[0] << 16;
				info->buf[i][j] += info->data->floor[1] << 8;
				info->buf[i][j] += info->data->floor[2];
			}
			else
			{
				info->buf[i][j] = info->data->ceil[0] << 16;
				info->buf[i][j] += info->data->ceil[1] << 8;
				info->buf[i][j] += info->data->ceil[2];
			}
			j++;
		}
		i++;
	}
}

void	draw_map_texture(t_info *info, t_mapcamera *mapcam, int i)
{
	
}

void	draw_mapcamera(t_info *info, t_mapcamera *mapcam, int i)
{
	if (mapcam->side == 0)
	{
		if (mapcam->raydir_x < 0)

		else

	}
	else
	{
		if (mapcam->raydir_y < 0)

		else
		
	}
	draw_map_texture(info, mapcam, i);
}
