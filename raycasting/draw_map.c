/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:41:58 by daheepark         #+#    #+#             */
/*   Updated: 2023/06/27 23:04:15 by daheepark        ###   ########.fr       */
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

