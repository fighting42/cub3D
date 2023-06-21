/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:01:20 by yejinkim          #+#    #+#             */
/*   Updated: 2023/06/21 21:40:29 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53
# define KEY_EXIT 17

typedef struct s_img
{
	int		width;
	int		height;
}	t_img;

typedef struct s_setting
{
	char	*east;
	char	*west;
	char	*south;
	char	*north;
	int		floor[3];
	int		ceil[3];
}	t_setting;

typedef struct s_info
{
	char		**map;
	t_setting	*setting;
	t_img		*img;
	void		*mlx;
	void		*win;
	double		pos_x;
	double		pos_y;
}	t_info;

#endif