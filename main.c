/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:25:58 by yejinkim          #+#    #+#             */
/*   Updated: 2023/06/25 18:13:05 by yejinkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(void)
{
	printf("Error\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		print_error();
	parsing(&info, argv[1]); // info 구조체의 "data", "map" 담아줍니당 (아직 map은 안담겨용ㅋㅎ)
	
	// mlx test
	// void *mlx_ptr = mlx_init();
	// void *win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "mlx 42");
	// mlx_loop(mlx_ptr);
	// mlx test
	return (0);
}
