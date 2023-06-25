/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:26:11 by yejinkim          #+#    #+#             */
/*   Updated: 2023/06/25 14:36:20 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_data(t_data *data)
{
	data->east = NULL;
	data->west = NULL;
	data->south = NULL;
	data->north = NULL;
	data->floor = -1;
	data->ceil = -1;
}
