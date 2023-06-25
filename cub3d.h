/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:01:20 by yejinkim          #+#    #+#             */
/*   Updated: 2023/06/25 16:23:32 by yejinkim         ###   ########seoul.kr  */
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

# define BUFFER_SIZE 42
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53
# define KEY_EXIT 17
# define WIDTH 640
# define HEIGHT 480
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define MAPWIDTH 24
# define MAPHEIGHT 24

typedef struct s_img
{
	int		width;
	int		height;
	int		*data;
}	t_img;

typedef struct s_data
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor; // rgb color int형으로 변환. 이거 그대로 사용하면 됨.
	int		ceil; // 위와 동일 !
}	t_data; // 구 t_setting.. 구조체 이름 변경했읍니다.. 이유는 내 맴..ㅋ..ㅎ

typedef struct s_info
{
	char	**map;
	t_data	*data;
	t_img	*img;
	void	*mlx;
	void	*win;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	movespeed;
	double	rotspeed;
	int		buf[WIDTH][HEIGHT];
}	t_info;

// main.c
void	print_error(void);

// parsing/parsing.c
void	parsing(t_data *data, char *file);
char	*parse_texture(char *var, char *str);
int		parse_color(int var, char *str);
void	parse_line(t_data *data, char *line);
void	check_data(t_data *data);
// parsing/init.c
void	init_data(t_data *data);
// parsing/utils.c
char	*remove_space(char *str);
char	*remove_space_back(char *str);
int		ft_atoi_255(char *str);
int		rgb_to_int(char **str);
// parsing/get_next_line.c
char	*get_next_line(int fd);

#endif