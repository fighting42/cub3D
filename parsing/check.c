/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   check.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yejinkim <yejinkim@student.42seoul.kr>	 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/07/04 15:45:37 by yejinkim		  #+#	#+#			 */
/*   Updated: 2023/07/04 15:50:48 by yejinkim		 ###   ########seoul.kr  */
/*																			*/
/* ************************************************************************** */

#include "../cub3d.h"

void	set_start_info(t_info *info, char c, int x, int y)
{
	if (info->start_dir)
		print_error("The player direction is duplicated on the map.");
	if (c == 'N')
		info->start_dir = 'W';
	else if (c == 'S')
		info->start_dir = 'S';
	else if (c == 'E')
		info->start_dir = 'D';
	else if (c == 'W')
		info->start_dir = 'A';
	info->pos_x = x;
	info->pos_y = y;
}

t_data	*check_data(t_data *data)
{
	if (!data->north)
		print_error("There is no 'NO' value.");
	if (!data->south)
		print_error("There is no 'SO' value.");
	if (!data->west)
		print_error("There is no 'WE' value.");
	if (!data->east)
		print_error("There is no 'EA' value.");
	if (data->floor < 0)
		print_error("There is no 'F' value.");
	if (data->ceil < 0)
		print_error("There is no 'C' value.");
	return (data);
}

void	check_wall(char **map, int i, int j, int flag)
{
	if (flag && map[i][j] == '0')
		print_error("The map is not surrounded by walls.");
	if (map[i - 1][j] == '\0')
		print_error("The map is not surrounded by walls.");
	if (map[i + 1][j] == '\0')
		print_error("The map is not surrounded by walls.");
	if (map[i][j - 1] == '\0')
		print_error("The map is not surrounded by walls.");
	if (map[i][j + 1] == '\0')
		print_error("The map is not surrounded by walls.");
}

char	**check_map(t_info *info, char **map, int w, int h)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	info->start_dir = '\0';
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			flag = 0;
			if (i == 0 || i == h || j == 0 || j == w)
				flag = 1;
			if (map[i][j] == '0')
				check_wall(map, i, j, flag);
			if (map[i][j] == 'N' || map[i][j] == 'S' \
				|| map[i][j] == 'W' || map[i][j] == 'E')
				set_start_info(info, map[i][j], i, j);
		}
	}
	if (!info->start_dir)
		print_error("The map does not have a player direction.");
	return (map);
}
