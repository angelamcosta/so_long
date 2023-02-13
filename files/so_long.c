/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:44 by anlima            #+#    #+#             */
/*   Updated: 2023/02/13 16:57:09 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_win	*create_win(void)
{
	static t_win	win;

	return (&win);
}


int	events(int keycode)
{
	// if (keycode)
	// 	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(create_win()->mlx, create_win()->mlx_win);
		exit(0);
	}
	// hardcoded window values for now
	if (keycode == 65363 || keycode == 65361 || keycode == 65364 || keycode == 65362 || keycode == 97 || keycode == 119 || keycode == 115 || keycode == 100)
	{
		if ((keycode == 65363 || keycode == 100) && (create_win()->x + 32 <= 416))
			create_win()->x += 32;
		if ((keycode == 65361 || keycode == 97) && (create_win()->x - 32 >= 32))
			create_win()->x -= 32;
		if ((keycode == 65364 || keycode == 115) && (create_win()->y + 32 <= 416))
			create_win()->y += 32;
		if ((keycode == 65362  || keycode == 119) && (create_win()->y - 32 >= 32))
			create_win()->y -= 32;
		mlx_clear_window(create_win()->mlx, create_win()->mlx_win);
		mlx_put_image_to_window(create_win()->mlx, create_win()->mlx_win, create_win()->img, create_win()->x, create_win()->y);
	}
	return (0);
}

int	main(void)
{
	create_win()->x = 32;
	create_win()->y = 32;
	create_win()->mlx = mlx_init();
	create_win()->mlx_win = mlx_new_window(create_win()->mlx, 480, 480, "cozy joguinh");
	create_win()->img = mlx_xpm_file_to_image(create_win()->mlx, "../assets/frog.xpm", &create_win()->img_width, &create_win()->img_height);
	mlx_clear_window(create_win()->mlx, create_win()->mlx_win);
	mlx_put_image_to_window(create_win()->mlx, create_win()->mlx_win, create_win()->img, create_win()->x, create_win()->y);
	mlx_hook(create_win()->mlx_win, 2, 1L<<0, events, create_win());
	mlx_loop(create_win()->mlx);
}
