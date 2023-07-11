/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:01:20 by yejinkim          #+#    #+#             */
/*   Updated: 2023/07/11 15:47:16 by yejinkim         ###   ########seoul.kr  */
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
# define KEY_RO_L 123
# define KEY_RO_R 124
# define KEY_ESC 53
# define KEY_EXIT 17
# define WIDTH 640
# define HEIGHT 480
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define K_ESC 53
# define N 1
# define S 2
# define E 3
# define W 4
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define FRONT 1
# define BACK 0

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
	int		endian;
	int		bpp;
	int		line_size;
	int		*data;
	int		tex_buf[64][64];
}	t_img;

typedef struct s_data
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceil;
}	t_data;

typedef struct s_line
{
	char			*str;
	struct s_line	*next;
}	t_line;

typedef struct s_map
{
	t_line	*line;
	int		max_w;
	int		max_h;
}	t_map;

typedef struct s_mapcamera
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perwalldist;
	int		line_height;
	int		start_point;
	int		end_point;
	int		step_x;
	int		step_y;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	int		hit;
	int		side;
	double	step;
}	t_mapcamera;

typedef struct s_info
{
	char	**map;
	char	start_dir;
	t_data	*data;
	t_img	img[5];
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
	int		buf[HEIGHT][WIDTH];
}	t_info;

// main.c
void	print_error(char *str);
int		red_press(void *value);
int		main(int argc, char **argv);

// parsing/parsing.c
void	parsing(t_info *info, char *file);
void	parse_line(char *file, t_data *data, t_map *tmp_map);
int		open_file(char *file);
t_map	*init_map(void);
t_data	*init_data(void);
// parsing/parse_data.c
int		parse_data(t_data *data, char *line);
int		parse_color(int var, char *str);
char	*parse_texture(char *var, char *str);
// parsing/parse_map.c
void	parse_map(t_map *map, char *line);
void	add_map_line(t_map *map, char *line);
t_line	*new_map_line(char *line);
void	set_start_info(t_info *info, char **map, int y, int x);
char	**malloc_map(t_map *tmp_map);
// parsing/check.c
char	**check_map(t_info *info, char **map, t_map *tmp_map);
void	check_wall(char **map, int i, int j, int flag);
t_data	*check_data(t_data *data);
void	check_xpm(char *file);
// parsing/utils.c
int		rgb_to_int(char **str);
int		ft_atoi_255(char *str);
char	*ft_strndup(char *str, int len);
char	*remove_space(char *str, int flag);
int		is_space(char c);
// parsing/get_next_line.c
char	*get_next_line(int fd);

// raycasting/raycasting.c
int		raycasting(t_info *info);
void	wall_x_or_y(t_info *info, t_mapcamera *mapcam);
void	set_moving_dir(t_info *info, t_mapcamera *mapcam);
void	set_mapcamera(t_info *info, t_mapcamera *mapcam, int i);
// raycasting/draw_map.c
void	draw_floor_ceil(t_info *info);
void	draw_map_texture(t_info *info, t_mapcamera *mapcam, int i, int dir);
void	draw_mapcamera(t_info *info, t_mapcamera *mapcam, int i);
void	draw_map(t_info *info);
// raycasting/keypress.c
void	keypress_wd(int keycode, t_info *info);
void	keypress_as(int keycode, t_info *info);
void	keypress_lr(int k, t_info *info, double ori_plane_x, double ori_dir_x);
int		key_press(int keycode, t_info *info);
// raycasting/set_info.c
void	start_dir_ns(t_info *info);
void	start_dir_ew(t_info *info);
void	init_buf(t_info *info);
void	set_info(t_info *info);
// raycasting/set_texture.c
void	set_texture_util(t_info *info, int dir, char *path);
void	set_texture(t_info *info);

#endif
