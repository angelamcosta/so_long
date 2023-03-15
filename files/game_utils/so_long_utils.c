/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:03:24 by anlima            #+#    #+#             */
/*   Updated: 2023/03/15 13:58:36 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_win	*create_win(void)
{
	static t_win	win;

	return (&win);
}

t_map	*create_map(void)
{
	static t_map	map;

	return (&map);
}

int	events(int keycode)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(create_win()->mlx, create_win()->mlx_win);
		exit(0);
	}
	// hardcoded window values for now
	if (keycode == 65363 || keycode == 65361 || keycode == 65364 || keycode == 65362 || keycode == 97 || keycode == 119 || keycode == 115 || keycode == 100)
	{
		if ((keycode == 65363 || keycode == 100) && (create_win()->x + PIXEL_SIZE < create_win()->win_width - PIXEL_SIZE) && print_moves())
			create_win()->x += PIXEL_SIZE;
		if ((keycode == 65361 || keycode == 97) && (create_win()->x - PIXEL_SIZE >= PIXEL_SIZE) && print_moves())
			create_win()->x -= PIXEL_SIZE;
		if ((keycode == 65364 || keycode == 115) && (create_win()->y + PIXEL_SIZE < create_win()->win_height - PIXEL_SIZE) && print_moves())
			create_win()->y += PIXEL_SIZE;
		if ((keycode == 65362  || keycode == 119) && (create_win()->y - PIXEL_SIZE >= PIXEL_SIZE) && print_moves())
			create_win()->y -= PIXEL_SIZE;
		create_background();
		mlx_put_image_to_window(create_win()->mlx, create_win()->mlx_win, create_win()->img, create_win()->x, create_win()->y);
	}
	return (0);
}

int	print_moves(void)
{
	create_win()->moves += 1;
	ft_putnbr(create_win()->moves);
	write(1, " moves\n", 7);
	return (1);
}

void	create_background(void)
{
	int	i;
	int	j;

	j = 0;
	while (j < create_win()->win_height)
	{
		i = 0;
		while (i < create_win()->win_width)
		{
			mlx_put_image_to_window(create_win()->mlx, create_win()->mlx_win, create_win()->background, i, j);
			i += PIXEL_SIZE;
		}
		j += PIXEL_SIZE;
	}
	mlx_put_image_to_window(create_win()->mlx, create_win()->mlx_win, create_win()->img, create_win()->x, create_win()->y);
}
