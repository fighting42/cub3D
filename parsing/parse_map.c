/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:32:03 by yejinkim          #+#    #+#             */
/*   Updated: 2023/06/25 16:32:03 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    check_map(char **map)
{
    (void)map;
}

void    parse_map(char **map, char *line)
{
    (void)map;
    int i;

    i = 0;
    while (line[i])
    {
        if (!(line[i] == '0' || line[i] == '1' || line[i] == ' ' || line[i] == '\n' \
            || line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W'))
            print_error(); // map 에러
        i++;
    }
}
