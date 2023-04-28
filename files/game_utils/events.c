/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:41:28 by anlima            #+#    #+#             */
/*   Updated: 2023/04/28 14:01:55 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		events_keys(int keycode);
int		events_buttons(int button);
void	key_events(int i, int j, int *val, int isSum);

int	events_keys(int keycode)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(create_win()->mlx, create_win()->mlx_win);
		exit(0);
	}
	if (keycode == 65363 || keycode == 100)
		key_events(create_map()->i, create_map()->j + 1, &create_map()->j, 1);
	if (keycode == 65361 || keycode == 97)
		key_events(create_map()->i, create_map()->j - 1, &create_map()->j, 0);
	if (keycode == 65364 || keycode == 115)
		key_events(create_map()->i + 1, create_map()->j, &create_map()->i, 1);
	if (keycode == 65362 || keycode == 119)
		key_events(create_map()->i - 1, create_map()->j, &create_map()->i, 0);
	moved();
	return (0);
}

int	events_buttons(int button)
{
	// if (keycode == 65307)
	// {
	// 	mlx_destroy_window(create_win()->mlx, create_win()->mlx_win);
	// 	exit(0);
	// }
	printf("%i", button);
	return (0);
}

void	key_events(int i, int j, int *val, int isSum)
{
	if ((create_map()->map[i][j] != '1') && print_moves() && isSum)
		val[0]++;
	else if ((create_map()->map[i][j] != '1') && print_moves() && !isSum)
		val[0]--;
}
