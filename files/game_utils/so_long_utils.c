/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:03:24 by anlima            #+#    #+#             */
/*   Updated: 2023/02/16 16:48:28 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		create_background();
		mlx_put_image_to_window(create_win()->mlx, create_win()->mlx_win, create_win()->img, create_win()->x, create_win()->y);
	}
	return (0);
}

void	create_background(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window(create_win()->mlx, create_win()->mlx_win);
	while (j < 481)
	{
		while (i < 481)
		{
			mlx_put_image_to_window(create_win()->mlx, create_win()->mlx_win, create_win()->background, i, j);
			i += 32;
		}
		i = 0;
		j += 32;
	}
	mlx_put_image_to_window(create_win()->mlx, create_win()->mlx_win, create_win()->img, create_win()->x, create_win()->y);
}
