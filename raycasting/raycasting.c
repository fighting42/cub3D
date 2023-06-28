/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:27:43 by yejinkim          #+#    #+#             */
/*   Updated: 2023/06/28 09:40:42 by daheepark        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
