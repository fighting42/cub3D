/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:25:58 by yejinkim          #+#    #+#             */
/*   Updated: 2023/06/25 14:37:07 by yejinkim         ###   ########seoul.kr  */
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
	t_data	data;

	if (argc != 2)
		print_error();
	parsing(&data, argv[1]);
	
	// mlx test
	// void *mlx_ptr = mlx_init();
	// void *win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "mlx 42");
	// mlx_loop(mlx_ptr);
	// mlx test
	return (0);
}
