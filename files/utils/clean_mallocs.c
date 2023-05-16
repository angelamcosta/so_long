/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mallocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:07:24 by anlima            #+#    #+#             */
/*   Updated: 2023/05/15 14:59:52 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	clean_mallocs(void);
void	destroy_images(void);
void	destroy_display(void);

void	clean_mallocs(void)
{
	int	i;

	i = 0;
	while (create_map()->map && create_map()->map[i])
		free(create_map()->map[i++]);
	if (create_map()->map)
		free(create_map()->map);
	destroy_images();
	destroy_display();
}

void	destroy_images(void)
{
	if (create_win()->background)
		mlx_destroy_image(create_win()->mlx, create_win()->background);
	if (create_win()->img)
		mlx_destroy_image(create_win()->mlx, create_win()->img);
	if (create_win()->collectible)
		mlx_destroy_image(create_win()->mlx, create_win()->collectible);
	if (create_win()->exit)
		mlx_destroy_image(create_win()->mlx, create_win()->exit);
	if (create_win()->wall)
		mlx_destroy_image(create_win()->mlx, create_win()->wall);
}

void	destroy_display(void)
{
	mlx_destroy_display(create_win()->mlx);
	free(create_win()->mlx);
}
