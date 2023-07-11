/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:32:06 by yejinkim          #+#    #+#             */
/*   Updated: 2023/07/11 21:11:17 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*parse_texture(char *var, char *str)
{
	char	*tmp;

	if (var)
		print_error("There are duplicate elements.");
	tmp = remove_space(&str[2], FRONT);
	tmp = remove_space(tmp, BACK);
	return (ft_strdup(tmp));
}

int	parse_color(int var, char *str)
{
	int		i;
	int		cnt;
	char	*tmp;
	char	**ret;

	if (var >= 0)
		print_error("There are duplicate elements.");
	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == ',')
			cnt++;
		i++;
	}
	if (cnt != 2)
		print_error("Invalid RGB format. (Valid format: R,G,B)");
	tmp = remove_space(&str[1], FRONT);
	ret = ft_split(tmp, ',');
	return (rgb_to_int(ret));
}

int	parse_data(t_data *data, char *line)
{
	char	*str;

	str = remove_space(line, FRONT);
	if (!ft_strncmp(str, "NO ", 3))
		data->north = parse_texture(data->north, str);
	else if (!ft_strncmp(str, "SO ", 3))
		data->south = parse_texture(data->south, str);
	else if (!ft_strncmp(str, "WE ", 3))
		data->west = parse_texture(data->west, str);
	else if (!ft_strncmp(str, "EA ", 3))
		data->east = parse_texture(data->east, str);
	else if (!ft_strncmp(str, "F ", 2))
		data->floor = parse_color(data->floor, str);
	else if (!ft_strncmp(str, "C ", 2))
		data->ceil = parse_color(data->ceil, str);
	else if (!ft_strlen(str))
		return (1);
	else
		return (0);
	return (1);
}
