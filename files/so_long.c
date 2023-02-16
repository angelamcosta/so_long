/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:44 by anlima            #+#    #+#             */
/*   Updated: 2023/02/16 18:02:33 by anlima           ###   ########.fr       */
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
	create_win()->x = 32;
	create_win()->y = 32;
	create_win()->mlx = mlx_init();
	create_win()->mlx_win = mlx_new_window(create_win()->mlx, 480, 480, "cozy joguinho");
	create_win()->background = mlx_xpm_file_to_image(create_win()->mlx, BCKGROUND, &create_win()->x, &create_win()->y);
	create_win()->img = mlx_xpm_file_to_image(create_win()->mlx, CHAR_IMG, &create_win()->x, &create_win()->y);
	create_background();
	mlx_hook(create_win()->mlx_win, 2, 1L<<0, events, create_win());
	mlx_loop(create_win()->mlx);
}
