/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:50:44 by anlima            #+#    #+#             */
/*   Updated: 2023/02/16 18:52:03 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_empty(int fd)
{
	int		cont;
	char	*temp;

	cont = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		cont++;
		free(temp);
		temp = get_next_line(fd);
	}
	free(temp);
	close(fd);
	return (cont);
}

int	is_valid(void)
{
	int	i;

	i = 0;
	while (create_win()->map && create_win()->map[i])
		printf("%s", create_win()->map[i++]);
	return (1);
}

int	verify_map(char *file_name)
{
	int		fd;
	int		cont;

	fd = open(file_name, O_RDONLY);
	cont = is_empty(fd);
	if (!cont)
		return (0);
	create_win()->map = (char **)malloc(sizeof(char *) * (cont + 1));
	if (!create_win()->map)
		return (0);
	fd = open(file_name, O_RDONLY);
	cont = 0;
	while (1)
	{
		create_win()->map[cont] = get_next_line(fd);
		if (!create_win()->map[cont])
			break ;
		cont++;
	}
	close(fd);
	return (is_valid());
}
