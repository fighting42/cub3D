/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:27:29 by yejinkim          #+#    #+#             */
/*   Updated: 2023/07/11 21:43:20 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(0);
	data->east = NULL;
	data->west = NULL;
	data->south = NULL;
	data->north = NULL;
	data->floor = -1;
	data->ceil = -1;
	return (data);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit(0);
	map->line = NULL;
	map->max_h = 0;
	map->max_w = 0;
	return (map);
}

int	open_file(char *file)
{
	int	i;
	int	fd;

	i = ft_strlen(file) - 4;
	if (i < 0)
		print_error("The file extension is not \".cub\".");
	if ((!ft_strncmp(file, ".cub", 4) && i == 0) || \
		(!ft_strncmp(&file[i - 1], "/.cub", 5) && i != 0) || \
		ft_strncmp(&file[i], ".cub", 4))
		print_error("The file extension is not \".cub\".");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("The file cannot be opened.");
	return (fd);
}

void	parse_line(char *file, t_data *data, t_map *tmp_map)
{
	int		fd;
	char	*line;
	int		flag;

	fd = open_file(file);
	line = "";
	flag = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			if (!parse_data(data, line) && !flag)
				flag = 1;
			if (flag)
				parse_map(tmp_map, line);
		}
		free(line);
	}
}

void	parsing(t_info *info, char *file)
{
	t_data	*data;
	t_map	*tmp_map;
	char	**map;

	data = init_data();
	tmp_map = init_map();
	parse_line(file, data, tmp_map);
	map = malloc_map(tmp_map);
	info->data = check_data(data);
	info->map = check_map(info, map, tmp_map);
}
