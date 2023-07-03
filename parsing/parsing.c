/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:27:29 by yejinkim          #+#    #+#             */
/*   Updated: 2023/06/26 15:38:43 by yejinkim         ###   ########seoul.kr  */
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
	int fd;

	i = ft_strlen(file) - 4;
	if (ft_strncmp(&file[i], ".cub", 4))
		print_error("The file extension is not \".cub\".");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("The file cannot be opened.");
	return (fd);
}

void	parsing(t_info *info, char *file)
{
	t_data	data;
	char	**map;
	t_map	*tmp_map;
	int		h;
	int		w;
	int		fd;
	char	*line;
	int		flag;

	fd = open_file(file);
	tmp_map = malloc(sizeof(t_map));
	tmp_map->line = NULL;
	init_data(&data);
	map = NULL;
	line = "";
	flag = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!parse_data(&data, line) && !flag)
			flag = 1;
		if (flag)
			parse_map(tmp_map, line);
		free(line);
	}
	free(line);
	w = tmp_map->max_w;
	h = tmp_map->max_h - 1;
	map = malloc_map(tmp_map);
	parse_map_info(info, map);
	check_data(&data);
	check_map(info, map, w, h);
	info->data = &data;
	info->map = map;
}
