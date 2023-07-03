/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:32:03 by yejinkim          #+#    #+#             */
/*   Updated: 2023/06/26 15:40:40 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    check_wall(char **map, int i, int j)
{
    if (map[i - 1][j] == ' ')
        print_error("The map is not surrounded by walls.");
    if (map[i + 1][j] == ' ')
        print_error("The map is not surrounded by walls.");
    if (map[i][j - 1] == ' ')
        print_error("The map is not surrounded by walls.");
    if (map[i][j + 1] == ' ')
        print_error("The map is not surrounded by walls.");
}

void    check_map(t_info *info, char **map, int w, int h)
{
    int i;
    int j;

    if (!info->start_dir)
        print_error("The map does not have a player direction.");
    
    i = 0;
    j = 0;
    if (ft_strchr(map[0], '0'))
        print_error("The map is not surrounded by walls.");
    if (ft_strchr(map[h], '0'))
        print_error("The map is not surrounded by walls.");
    while (map[i])
    {
        j = 0;
        if (map[i][j] == '0')
            print_error("The map is not surrounded by walls.");
        while (map[i][j])
        {
            if (map[i][j] == '0' && !(i == 0 || j == 0) && !(i == h || j == w))
                check_wall(map, i, j);
            j++;
        }
        if (map[i][j - 1] == '0')
            print_error("The map is not surrounded by walls.");
        i++;
    }
}

void    set_start_info(t_info *info, char c, int x, int y)
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

void	parse_map_info(t_info *info, char **map)
{
    int x;
    int y;

    info->start_dir = '\0';
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
                set_start_info(info, map[y][x], x, y);
            x++;
        }
        y++;
    }
}

char    **malloc_map(t_map *tmp_map)
{
    char    **map;
    t_map   *tmp;
    t_map   *free_tmp;
    int     i;
    int     j;
    int     width;

    if (!tmp_map->line)
        print_error("There is no map value.");
    map = malloc(sizeof(char *) * (tmp_map->max_h + 1));
    tmp = tmp_map;
    width = tmp_map->max_w + 1;
    i = 0;
    while (tmp)
    {
        map[i] = malloc(sizeof(char) * width);
        j = 0;
        while (j < (int)ft_strlen(tmp->line))
        {
            map[i][j] = tmp->line[j];
            j++;
        }
        while (j < width)
            map[i][j++] = ' ';
        map[i][j] = '\0';
        free(tmp->line);
        free_tmp = tmp;
        tmp = tmp->next;
        free(free_tmp);
        i++;
    }
    map[i] = NULL;
    return (map);
}

void    add_map_line(t_map *map, char *line)
{
    static int  h;
    int         len;
    t_map       *tmp;

    line = remove_space_back(line);
    len = ft_strlen(line);
    h++;
    if (!map->line)
    {
        map->line = ft_strdup(line);
        map->max_w = len;
        map->max_h = h;
        map->next = NULL;
    }
    else
    {
        tmp = map;
        while (tmp->next)
        {
            if (tmp->max_w < len)
                tmp->max_w = len;
            tmp->max_h = h;
            tmp = tmp->next;
        }
        if (tmp->max_w < len)
            tmp->max_w = len;
        tmp->max_h = h;
        tmp->next = malloc(sizeof(t_map));
        tmp->next->line = ft_strdup(line);
        if (tmp->next->max_w < len)
            tmp->next->max_w = len;
        tmp->next->max_h = h;
        tmp->next->next = NULL;
    }
}

void    parse_map(t_map *map, char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (!(line[i] == '0' || line[i] == '1' || is_space(line[i]) \
            || line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W'))
            print_error("The map contains invalid values. (Valid values: 0, 1, N, S, E, W)");
        i++;
    }
	if (ft_strlen(remove_space(line)) == 0)
		print_error("There is an empty line in the map.");
    add_map_line(map, line);
}
