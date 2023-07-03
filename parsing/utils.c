/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:47:04 by yejinkim          #+#    #+#             */
/*   Updated: 2023/06/26 15:20:14 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

char	*remove_space(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	return (&str[i]);
}

char	*remove_space_back(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (is_space(str[i]))
		i--;
	str[++i] = 0;
	return (str);
}

int	ft_atoi_255(char *str)
{
	int	i;
	int	tmp;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || is_space(str[i])))
			print_error("The RGB value is not a number.");
		i++;
	}
	if (i == 0)
		print_error("The RGB value is not a number.");
	tmp = ft_atoi(str);
	if (!(tmp >= 0 && tmp <= 255))
		print_error("Invalid RGB value. (Valid range: 0 to 255)");
	return (tmp);
}

int	rgb_to_int(char **str)
{
	int	i;
	int	tmp;

	i = 0;
	while (str[i])
		i++;
	if (i != 3)
		print_error("Invalid RGB format. (Valid format: R, G, B)");
	tmp = ft_atoi_255(str[0]) << 16;
	tmp += ft_atoi_255(str[1]) << 8;
	tmp += ft_atoi_255(str[2]);
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (tmp);
}
