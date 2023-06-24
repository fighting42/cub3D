/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:27:29 by yejinkim          #+#    #+#             */
/*   Updated: 2023/06/24 22:10:46 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*remove_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (&str[i]);
}

char	*remove_space_back(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i] == ' ' || str[i] == '\n' || (str[i] >= 9 && str[i] <= 13))
		i--;
	str[++i] = 0;
	return (str);
}

char	*check_setting(char *var, char *str)
{
	char	*tmp;

	if (var)
		print_error();
	tmp = remove_space(&str[2]);
	tmp = remove_space_back(tmp);
	return (ft_strdup(tmp));
}

int	*check_setting_num(char *str)
{
	char	*tmp;
	char	**ret;
	

	tmp = remove_space(&str[1]);
	ret = ft_split(tmp, ',');
	//printf("ret: %s %s %s %s\n", ret[0], ret[1], ret[2], ret[3]);
	return (0);
}

void	check_element(t_setting *setting, char *line)
{
	char	*str;

	str = remove_space(line);
	if (!ft_strncmp(str, "NO ", 3))
		setting->north = check_setting(setting->north, str);
	else if (!ft_strncmp(str, "SO ", 3))
		setting->south = check_setting(setting->south, str);
	else if (!ft_strncmp(str, "WE ", 3))
		setting->west = check_setting(setting->west, str);
	else if (!ft_strncmp(str, "EA ", 3))
		setting->east = check_setting(setting->east, str);
	else if (!ft_strncmp(str, "F ", 2))
		check_setting_num(str);
	else if (!ft_strncmp(str, "C ", 2))
		check_setting_num(str);
}

void	parsing(t_setting *setting, char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = ft_strlen(file) - 4;
	if (ft_strncmp(&file[i], ".cub", 4))
		print_error();
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error();
	
	init_setting(setting);

	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_element(setting, line);
		free(line);
	}
	
	//printf("%s\n%s\n%s\n%s\n", setting->north, setting->south, setting->west, setting->east);
}
