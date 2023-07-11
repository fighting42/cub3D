/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:45:37 by yejinkim          #+#    #+#             */
/*   Updated: 2023/07/11 21:46:06 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_xpm(char *file)
{
	int	i;
	int	fd;

	if (!file)
		print_error("There are empty elements.");
	i = ft_strlen(file) - 4;
	if (i < 0)
		print_error("The extension of the texture file is not \".xpm\".");
	if ((!ft_strncmp(file, ".xpm", 4) && i == 0) || \
		(!ft_strncmp(&file[i - 1], "/.xpm", 5) && i != 0) || \
		ft_strncmp(&file[i], ".xpm", 4))
		print_error("The extension of the texture file is not \".xpm\".");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("The texture file cannot be opened.");
	close(fd);
}

t_data	*check_data(t_data *data)
{	
	check_xpm(data->north);
	check_xpm(data->south);
	check_xpm(data->west);
	check_xpm(data->east);
	if (data->floor < 0 || data->ceil < 0)
		print_error("There are empty elements.");
	return (data);
}

void	check_wall(char **map, int i, int j, int flag)
{
	if (flag && map[i][j] == '0')
		print_error("The map is not surrounded by walls.");
	if (map[i - 1][j] == ' ')
		print_error("The map is not surrounded by walls.");
	if (map[i + 1][j] == ' ')
		print_error("The map is not surrounded by walls.");
	if (map[i][j - 1] == ' ')
		print_error("The map is not surrounded by walls.");
	if (map[i][j + 1] == ' ')
		print_error("The map is not surrounded by walls.");
}

char	**check_map(t_info *info, char **map, t_map *tmp_map)
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
			if (i == 0 || i == tmp_map->max_h || j == 0 || j == tmp_map->max_w)
				flag = 1;
			if (map[i][j] == '0')
				check_wall(map, i, j, flag);
			if (map[i][j] == 'N' || map[i][j] == 'S' \
				|| map[i][j] == 'W' || map[i][j] == 'E')
				set_start_info(info, map, i, j);
		}
	}
	if (!info->start_dir)
		print_error("The map does not have a player direction.");
	free(tmp_map);
	return (map);
}
