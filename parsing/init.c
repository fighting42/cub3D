/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:26:11 by yejinkim          #+#    #+#             */
/*   Updated: 2023/06/24 19:44:46 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_setting(t_setting *setting)
{
	setting->east = NULL;
	setting->west = NULL;
	setting->south = NULL;
	setting->north = NULL;
	setting->floor[0] = -1;
	setting->ceil[0] = -1;
}
