/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:25:58 by yejinkim          #+#    #+#             */
/*   Updated: 2023/07/07 02:04:00 by daheepark        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	exit(0);
}

int	red_press(void *value)
{
	(void)value;
	value = NULL;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		print_error("The number of arguments is not 1.");
	parsing(&info, argv[1]);
	set_info(&info);
	mlx_loop_hook(info.mlx, &raycasting, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, 17, 0, red_press, NULL);
	mlx_loop(info.mlx);
	exit(0);
}
