/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:03:24 by anlima            #+#    #+#             */
/*   Updated: 2023/04/13 14:32:47 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_win	*create_win(void);
t_map	*create_map(void);
int		events(int keycode);
int		print_moves(void);
int		moved(void);

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
	if ((keycode == 65363 || keycode == 100)
		&& (create_map()->map[create_map()->i][create_map()->j + 1] != '1')
		&& print_moves())
		create_map()->j++;
	if ((keycode == 65361 || keycode == 97)
		&& (create_map()->map[create_map()->i][create_map()->j - 1] != '1')
		&& print_moves())
		create_map()->j--;
	if ((keycode == 65364 || keycode == 115)
		&& (create_map()->map[create_map()->i + 1][create_map()->j] != '1')
		&& print_moves())
		create_map()->i++;
	if ((keycode == 65362 || keycode == 119)
		&& (create_map()->map[create_map()->i - 1][create_map()->j] != '1')
		&& print_moves())
		create_map()->i--;
	moved();
	return (0);
}

int	print_moves(void)
{
	create_win()->moves += 1;
	ft_putnbr(create_win()->moves);
	write(1, " moves\n", 7);
	return (1);
}

int	moved(void)
{
	create_background();
	collect_itens();
	put_items();
	mlx_put_image_to_window(create_win()->mlx, create_win()->mlx_win,
		create_win()->img, create_map()->j * PIXEL_SIZE, create_map()->i
		* PIXEL_SIZE);
	return (1);
}
