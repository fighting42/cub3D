/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:32:03 by yejinkim          #+#    #+#             */
/*   Updated: 2023/07/11 15:16:43 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**malloc_map(t_map *tmp_map)
{
	char	**map;
	t_line	*line;
	t_line	*free_tmp;
	int		i;

	if (!tmp_map->line)
		print_error("There is no map value.");
	map = malloc(sizeof(char *) * (tmp_map->max_h + 1));
	if (!map)
		exit(0);
	line = tmp_map->line;
	i = 0;
	while (line)
	{
		map[i++] = ft_strndup(line->str, tmp_map->max_w + 1);
		free(line->str);
		free_tmp = line;
		line = line->next;
		free(free_tmp);
	}
	map[i] = NULL;
	return (map);
}

void	set_start_info(t_info *info, char **map, int y, int x)
{
	if (info->start_dir)
		print_error("The player direction is duplicated on the map.");
	info->start_dir = map[y][x];
	info->pos_x = x + 0.5;
	info->pos_y = y + 0.5;
	map[y][x] = '0';
}

t_line	*new_map_line(char *str)
{
	t_line	*new_line;

	str = remove_space(str, BACK);
	new_line = malloc(sizeof(t_line));
	if (!new_line)
		exit(0);
	new_line->str = ft_strdup(str);
	new_line->next = NULL;
	return (new_line);
}

void	add_map_line(t_map *map, char *line)
{
	t_line	*head;

	head = map->line;
	if (!head)
	{
		map->line = new_map_line(line);
		map->max_h++;
		map->max_w = ft_strlen(line);
	}
	else
	{
		while (head->next)
			head = head->next;
		head->next = new_map_line(line);
		map->max_h++;
		if (map->max_w < (int)ft_strlen(line))
			map->max_w = ft_strlen(line);
	}
}

void	parse_map(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == '0' || line[i] == '1' || is_space(line[i]) || line[i] \
			== 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W'))
			print_error("Invalid value.");
		i++;
	}
	if (ft_strlen(remove_space(line, FRONT)) == 0)
		print_error("There is an empty line in the map.");
	add_map_line(map, line);
}
