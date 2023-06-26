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
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
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
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '+' \
			|| str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			print_error(); // rgb 값(숫자 x) 에러
		i++;
	}
	if (i == 0)
		print_error(); // rgb 값(숫자 x) 에러
	tmp = ft_atoi(str);
	if (!(tmp >= 0 && tmp <= 255))
		print_error(); // rgb 범위 에러
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
		print_error(); // rgb format(',' 2개) 에러
	tmp = ft_atoi_255(str[0]) << 16;
	tmp += ft_atoi_255(str[1]) << 8;
	tmp += ft_atoi_255(str[2]);
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (tmp);
}
