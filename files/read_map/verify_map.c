/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:50:44 by anlima            #+#    #+#             */
/*   Updated: 2023/03/14 15:43:43 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	verify_map(char *filename)
{
	int		fd;
	int		cont;

	fd = open(filename, O_RDONLY);
	cont = is_empty(fd);
	if (!cont || cont < 3)
		return (0);
	create_map()->map = (char **)malloc(sizeof(char *) * (cont + 1));
	if (!create_map()->map)
		return (0);
	fd = open(filename, O_RDONLY);
	cont = 0;
	while (1)
	{
		create_map()->map[cont] = get_next_line(fd);
		if (!create_map()->map[cont])
			break ;
		cont++;
	}
	close(fd);
	return (is_valid());
}
