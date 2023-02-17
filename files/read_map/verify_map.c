/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:50:44 by anlima            #+#    #+#             */
/*   Updated: 2023/02/17 15:30:27 by anlima           ###   ########.fr       */
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
	int		i;
	size_t	j;

	i = 0;
	if (create_win()->map && create_win()->map[i])
		j = ft_strlen(create_win()->map[i++]);
	while (create_win()->map && create_win()->map[i])
	{
		if (!create_win()->map[i + 1])
			j--;
		if (ft_strlen(create_win()->map[i++]) != j)
			return (0);
	}
	return (1);
}

int	verify_map(char *file_name)
{
	int		fd;
	int		cont;

	fd = open(file_name, O_RDONLY);
	cont = is_empty(fd);
	if (!cont || cont < 3)
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
