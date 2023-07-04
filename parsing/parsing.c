/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:27:29 by yejinkim          #+#    #+#             */
/*   Updated: 2023/07/04 17:15:58 by yejinkim         ###   ########seoul.kr  */
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

int	open_file(char *file)
{
	int	i;
	int	fd;

	i = ft_strlen(file) - 4;
	if (ft_strncmp(&file[i], ".cub", 4))
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
		if (!line)
			break ;
		if (!parse_data(data, line) && !flag)
			flag = 1;
		if (flag)
			parse_map(tmp_map, line);
		free(line);
	}
	free(line);
}

void	parsing(t_info *info, char *file)
{
	t_data	*data;
	t_map	*tmp_map;
	char	**map;
	int		w;
	int		h;

	data = malloc(sizeof(t_data));
	init_data(data);
	tmp_map = malloc(sizeof(t_map));
	tmp_map->line = NULL;
	parse_line(file, data, tmp_map);
	w = tmp_map->max_w;
	h = tmp_map->max_h - 1;
	map = malloc_map(tmp_map);
	info->data = check_data(data);
	info->map = check_map(info, map, w, h);
}
