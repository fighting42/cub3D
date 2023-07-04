/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   parse_map.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yejinkim <yejinkim@student.42seoul.kr>	 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/06/25 16:32:03 by yejinkim		  #+#	#+#			 */
/*   Updated: 2023/07/04 15:46:17 by yejinkim		 ###   ########seoul.kr  */
/*																			*/
/* ************************************************************************** */

#include "../cub3d.h"

char	**malloc_map(t_map *tmp_map)
{
	char	**map;
	t_map	*tmp;
	t_map	*free_tmp;
	int		i;
	int		width;

	if (!tmp_map->line)
		print_error("There is no map value.");
	map = malloc(sizeof(char *) * (tmp_map->max_h + 1));
	tmp = tmp_map;
	width = tmp_map->max_w + 1;
	i = 0;
	while (tmp)
	{
		map[i] = ft_strndup(tmp->line, width);
		free(tmp->line);
		free_tmp = tmp;
		tmp = tmp->next;
		free(free_tmp);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	chage_max(t_map *map, int len, int h)
{
	if (map->max_w < len)
		map->max_w = len;
	map->max_h = h;
}

void	new_map_line(t_map *map, char *line, int h, int len)
{
	map->line = ft_strdup(line);
	map->next = NULL;
	if (h == 1)
	{
		map->max_w = len;
		map->max_h = h;
	}
	else
		chage_max(map, len, h);
	printf("max_w: %d, map_y: %d\n", map->max_w, map->max_h);
}

void	add_map_line(t_map *map, char *line)
{
	static int	h;
	int			len;
	t_map		*tmp;

	line = remove_space(line, BACK);
	len = ft_strlen(line);
	h++;
	if (!map->line)
		new_map_line(map, line, h, len);
	else
	{
		tmp = map;
		while (tmp->next)
		{
			chage_max(tmp, len, h);
			tmp = tmp->next;
		}
		chage_max(tmp, len, h);
		tmp->next = malloc(sizeof(t_map));
		new_map_line(tmp->next, line, h, len);
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
			print_error("The map contains invalid values. \
				(Valid values: 0, 1, N, S, E, W)");
		i++;
	}
	if (ft_strlen(remove_space(line, FRONT)) == 0)
		print_error("There is an empty line in the map.");
	add_map_line(map, line);
}
