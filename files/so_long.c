/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:44 by anlima            #+#    #+#             */
/*   Updated: 2023/04/13 14:35:14 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (!verify_map(argv[1]) || argc != 2)
	{
		write(1, "Args invalidos\n", 15);
		return (0);
	}
	create_win()->win_height = PIXEL_SIZE * create_map()->y;
	create_win()->win_width = PIXEL_SIZE * create_map()->x;
	create_win()->mlx = mlx_init();
	create_win()->mlx_win = mlx_new_window(create_win()->mlx, create_win()->win_width, create_win()->win_height, WIN_NAME);
	create_win()->background = mlx_xpm_file_to_image(create_win()->mlx, BCKGROUND, &create_win()->x, &create_win()->y);
	create_win()->img = mlx_xpm_file_to_image(create_win()->mlx, CHAR_IMG, &create_win()->x, &create_win()->y);
	create_win()->collectible = mlx_xpm_file_to_image(create_win()->mlx, COLLECTIBLE, &create_win()->x, &create_win()->y);
	create_win()->exit = mlx_xpm_file_to_image(create_win()->mlx, EXIT, &create_win()->x, &create_win()->y);
	create_win()->wall = mlx_xpm_file_to_image(create_win()->mlx, WALL, &create_win()->x, &create_win()->y);
	create_background();
	put_items();
	mlx_put_image_to_window(create_win()->mlx, create_win()->mlx_win, create_win()->img, create_map()->j * PIXEL_SIZE, create_map()->i * PIXEL_SIZE);
	mlx_hook(create_win()->mlx_win, 2, 1L<<0, events, create_win());
	mlx_loop(create_win()->mlx);
}
