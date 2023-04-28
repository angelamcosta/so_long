/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:03:24 by anlima            #+#    #+#             */
/*   Updated: 2023/04/28 13:41:43 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_win	*create_win(void);
t_map	*create_map(void);
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
