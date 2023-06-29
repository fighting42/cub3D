/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:26:25 by dapark            #+#    #+#             */
/*   Updated: 2023/06/29 17:41:33 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	keypress_wd(int keycode, t_info *info)
{
	if (keycode == KEY_D)
	{
		if (info->map[(int)(info->pos_x + info->plane_x * info->movespeed)]
				[(int)(info->pos_y)] != '1')
			info->pos_x += info->plane_x * info->movespeed;
		if (info->map[(int)(info->pos_x)]
				[(int)(info->pos_y + info->plane_y * info->movespeed)] != '1')
			info->pos_y += info->plane_y * info->movespeed;
	}
	else if (keycode == KEY_W)
	{
		if (info->map[(int)(info->pos_x + info->dir_x * info->movespeed)]
				[(int)(info->pos_y)] != '1')
			info->pos_x += info->dir_x * info->movespeed;
		if (info->map[(int)(info->pos_x)]
				[(int)(info->pos_y + info->dir_y * info->movespeed)] != '1')
			info->pos_y += info->dir_y * info->movespeed;
	}
}

void	keypress_as(int keycode, t_info *info)
{
	if (keycode == KEY_A)
	{
		if (info->map[(int)(info->pos_x - info->plane_x * info->movespeed)]
				[(int)(info->pos_y)] != '1')
			info->pos_x -= info->plane_x * info->movespeed;
		if (info->map[(int)(info->pos_x)]
				[(int)(info->pos_y - info->plane_y * info->movespeed)] != '1')
			info->pos_y -= info->plane_y * info->movespeed;
	}
	else if (keycode == KEY_S)
	{
		if (info->map[(int)(info->pos_x - info->dir_x * info->movespeed)]
				[(int)(info->pos_y)] != '1')
			info->pos_x -= info->dir_x * info->movespeed;
		if (info->map[(int)(info->pos_x)]
				[(int)(info->pos_y - info->dir_y * info->movespeed)] != '1')
			info->pos_y -= info->dir_y * info->movespeed;
	}
}

void	keypress_lr(int keycode, t_info *info)
{
	if (keycode == KEY_RO_L)
	{
		
	}
	else if (keycode == KEY_RO_R)
	{
		
	}
}

int	key_press(int keycode, t_info *info)
{
	if (keycode == KEY_A || keycode == KEY_S)
		keypress_as(keycode, info);
	if (keycode == KEY_D || keycode == KEY_W)
		keypress_wd(keycode, info);
	if (keycode == KEY_RO_L || keycode == KEY_RO_R)
		keypress_lr(keycode, info);
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
