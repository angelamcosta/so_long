/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:44 by anlima            #+#    #+#             */
/*   Updated: 2023/05/15 14:05:18 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_win	*win;

	if (!verify_map(argv[1]) || argc != 2)
		return (write(1, "Args invalidos\n", 15));
	create_win()->win_height = PIXEL_SIZE * create_map()->y;
	create_win()->win_width = PIXEL_SIZE * create_map()->x;
	win = create_win();
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, win->win_width,
			win->win_height, WIN_NAME);
	win->background = mlx_xpm_file_to_image(win->mlx, BCKGROUND,
			&win->x, &win->y);
	win->img = mlx_xpm_file_to_image(win->mlx, CHAR_IMG,
			&win->x, &win->y);
	win->collectible = mlx_xpm_file_to_image(win->mlx,
			COLLECTIBLE, &win->x, &win->y);
	win->exit = mlx_xpm_file_to_image(win->mlx, EXIT, &win->x, &win->y);
	win->wall = mlx_xpm_file_to_image(win->mlx, WALL, &win->x, &win->y);
	create_background();
	put_items();
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img,
		create_map()->j * PIXEL_SIZE, create_map()->i * PIXEL_SIZE);
	mlx_hook(win->mlx_win, 2, 1L << 0, events_keys, win);
	mlx_hook(win->mlx_win, 17, 1L << 0, close_win, win);
	mlx_loop(win->mlx);
}
