/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:44 by anlima            #+#    #+#             */
/*   Updated: 2023/02/13 13:30:30 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_wins	*create_win(void)
{
	static t_wins	win;

	return (&win);
}

int	main(void)
{
	void	*temp;

	create_win()->mlx = mlx_init();
	temp = mlx_new_window(create_win()->mlx, 500, 500, "cozy joguinho");
	create_win()->mlx_win = temp;
	mlx_loop(create_win()->mlx);
}
