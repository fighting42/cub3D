/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:32:06 by yejinkim          #+#    #+#             */
/*   Updated: 2023/06/25 16:32:06 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*parse_texture(char *var, char *str)
{
	char	*tmp;

	if (var)
		print_error(); // 중복 요소 에러
	tmp = remove_space(&str[2]);
	tmp = remove_space_back(tmp);
	return (ft_strdup(tmp));
}

int	parse_color(int var, char *str)
{
	char	*tmp;
	char	**ret;
	
	if (var >= 0)
		print_error(); // 중복 요소 에러
	tmp = remove_space(&str[1]);
	ret = ft_split(tmp, ',');
	return (rgb_to_int(ret));
}

void	check_data(t_data *data)
{
	// 요소 없음 에러
	if (!data->north)
		print_error();
	if (!data->south)
		print_error();
	if (!data->west)
		print_error();
	if (!data->east)
		print_error();
	if (data->floor < 0)
		print_error();
	if (data->ceil < 0)
		print_error();
}

int	parse_data(t_data *data, char *line)
{
	char	*str;

	str = remove_space(line);
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
	else if (!ft_strlen(str)) // map 중간에 개행 있으면 error ?
		return (1);
	else
		return (0);
	return (1);
}
