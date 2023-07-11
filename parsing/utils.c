/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:47:04 by yejinkim          #+#    #+#             */
/*   Updated: 2023/07/11 21:29:01 by yejinkim         ###   ########seoul.kr  */
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

char	*remove_space(char *str, int flag)
{
	int	i;

	if (flag == FRONT)
	{
		i = 0;
		while (is_space(str[i]))
			i++;
		return (&str[i]);
	}
	else
	{
		i = ft_strlen(str) - 1;
		while (is_space(str[i]))
			i--;
		str[++i] = 0;
		return (str);
	}
}

char	*ft_strndup(char *str, int len)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc(sizeof(char) * len);
	if (!ret)
		exit(0);
	while (i < (int)ft_strlen(str))
	{
		ret[i] = str[i];
		i++;
	}
	while (i < len - 1)
		ret[i++] = ' ';
	ret[i] = '\0';
	return (ret);
}

int	ft_atoi_255(char *str)
{
	int	i;
	int	tmp;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || is_space(str[i])))
			print_error("Invalid RGB value. (Valid range: 0 to 255)");
		i++;
	}
	tmp = ft_atoi(str);
	if (!(tmp >= 0 && tmp <= 255))
		print_error("Invalid RGB value. (Valid range: 0 to 255)");
	return (tmp);
}

int	rgb_to_int(char **str)
{
	char	*tmp;
	int		i;
	int		ret;

	i = 0;
	while (str[i])
	{
		tmp = remove_space(str[i], FRONT);
		if (!ft_strlen(tmp))
			print_error("Invalid RGB value.");
		i++;
	}
	if (i != 3)
		print_error("Invalid RGB format. (Valid format: R,G,B)");
	ret = ft_atoi_255(str[0]) << 16;
	ret += ft_atoi_255(str[1]) << 8;
	ret += ft_atoi_255(str[2]);
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (ret);
}
