/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:41:58 by daheepark         #+#    #+#             */
/*   Updated: 2023/07/10 20:03:03 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_floor_ceil(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i > HEIGHT / 2) // 부등호 방향 수정
				info->buf[i][j] = info->data->floor;
			else
				info->buf[i][j] = info->data->ceil;
			j++;
		}
		i++;
	}
}

void	draw_map_texture(t_info *info, t_mapcamera *mapcam, int i, int dir)
{
	if (mapcam->side == 0)
		mapcam->wall_x = info->pos_y + mapcam->perwalldist * mapcam->raydir_y;
	else
		mapcam->wall_x = info->pos_x + mapcam->perwalldist * mapcam->raydir_x;
	mapcam->wall_x -= floor(mapcam->wall_x);
	mapcam->tex_x = (int)(mapcam->wall_x * (double)TEXWIDTH);
	if (mapcam->side == 0 && mapcam->raydir_x > 0)
		mapcam->tex_x = TEXWIDTH - mapcam->tex_x - 1;
	if (mapcam->side == 1 && mapcam->raydir_y < 0)
		mapcam->tex_x = TEXWIDTH - mapcam->tex_x - 1;
	mapcam->step = 1.0 * TEXHEIGHT / mapcam->line_height;
	mapcam->tex_pos = (mapcam->start_point - HEIGHT
			/ 2 + mapcam->line_height / 2) * mapcam->step;
	while (0 < mapcam->start_point && mapcam->start_point < mapcam->end_point) // 수정 (0 < 조건 추가)
	{
		mapcam->tex_y = (int)mapcam->tex_pos & (TEXHEIGHT - 1);
		mapcam->tex_pos += mapcam->step;
		info->buf[mapcam->start_point][i] = \
			info->img[dir].tex_buf[mapcam->tex_y][mapcam->tex_x]; //x, y ㅎㅘㄱ인  // 원래대로 돌려놈
		mapcam->start_point++;
	}
}

void	draw_mapcamera(t_info *info, t_mapcamera *mapcam, int i)
{
	int	dir;

	if (mapcam->side == 0)
	{
		if (mapcam->raydir_x < 0)
			dir = E;
		else
			dir = W;
	}
	else
	{
		if (mapcam->raydir_y < 0)
			dir = S;
		else
			dir = N;
	}
	draw_map_texture(info, mapcam, i, dir);
}

void	draw_map(t_info *info)
{
	int	i;
	int	j;
	int	*buffer;

	i = 0;
	buffer = (int *)malloc(sizeof(int) * WIDTH * HEIGHT);
	while (i < HEIGHT) // 수정
	{
		j = 0;
		while (j < WIDTH) // 수정
		{
			buffer[WIDTH * i + j] = info->buf[i][j];
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(info->mlx, info->win, buffer, 0, 0);
}
