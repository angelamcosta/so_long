/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:50:12 by anlima            #+#    #+#             */
/*   Updated: 2023/03/16 15:11:33 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_background(void);
void	put_items(void);

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
}

void	put_items(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (create_map()->map && create_map()->map[i])
	{
		j = ft_strlen(create_map()->map[i]);
		k = 0;
		while (k < j)
		{
			if (create_map()->map[i][k] == '1')
				mlx_put_image_to_window(create_win()->mlx, create_win()->mlx_win, create_win()->wall, k * PIXEL_SIZE, i * PIXEL_SIZE);
			if (create_map()->map[i][k] == 'c')
				mlx_put_image_to_window(create_win()->mlx, create_win()->mlx_win, create_win()->collectible, k * PIXEL_SIZE, i * PIXEL_SIZE);
			if (create_map()->map[i][k] == 'e')
				mlx_put_image_to_window(create_win()->mlx, create_win()->mlx_win, create_win()->exit, k * PIXEL_SIZE, i * PIXEL_SIZE);
			k++;
		}
		i++;
	}
}

void	collect_itens(void)
{
	if (create_map()->map[create_map()->i][create_map()->j] == 'c')
	{
		create_map()->map[create_map()->i][create_map()->j] = '0';
		create_win()->c += 1;
	}
	if (create_map()->map[create_map()->i][create_map()->j] == 'e' && (create_win()->c == create_map()->c))
	{
		mlx_destroy_window(create_win()->mlx, create_win()->mlx_win);
		exit(0);
	}
}
