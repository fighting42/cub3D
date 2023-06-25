/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:27:29 by yejinkim          #+#    #+#             */
/*   Updated: 2023/06/25 17:52:49 by yejinkim         ###   ########seoul.kr  */
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

void	parsing(t_info *info, char *file)
{
	t_data	data;
	char	**map;
	int		i;
	int		fd;
	char	*line;

	i = ft_strlen(file) - 4;
	if (ft_strncmp(&file[i], ".cub", 4))
		print_error(); // 파일 확장자 에러
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error(); // 파일 오픈 에러

	init_data(&data);
	map = NULL;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!parse_data(&data, line))
			parse_map(map, line);
		free(line);
	}
	free(line);

	check_data(&data);
	check_map(map);
	info->data = &data;
	info->map = map;
}
