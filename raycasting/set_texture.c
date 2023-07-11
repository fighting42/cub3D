/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:09:14 by dapark            #+#    #+#             */
/*   Updated: 2023/07/11 20:52:43 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_texture_util(t_info *info, int dir, char *path)
{
	int	i;
	int	j;

	i = 0;
	info->img[dir].img = mlx_xpm_file_to_image(info->mlx, path, \
						&info->img[dir].width, &info->img[dir].height);
	if (!info->img[dir].img)
		print_error("Invalid texture file.");
	info->img[dir].data = (int *)mlx_get_data_addr(info->img[dir].img, \
		&info->img[dir].bpp, &info->img[dir].line_size, &info->img[dir].endian);
	while (i < info->img[dir].height)
	{
		j = 0;
		while (j < info->img[dir].width)
		{
			info->img[dir].tex_buf[i][j] = \
				info->img[dir].data[info->img[dir].width * i + j];
			j++;
		}
		i++;
	}
}

void	set_texture(t_info *info)
{
	set_texture_util(info, N, info->data->north);
	set_texture_util(info, S, info->data->south);
	set_texture_util(info, E, info->data->east);
	set_texture_util(info, W, info->data->west);
}
