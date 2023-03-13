/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:50:44 by anlima            #+#    #+#             */
/*   Updated: 2023/03/13 22:01:51 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_chars(void)
{
	if (create_win()->c < 1 || create_win()->p != 1 || create_win()->e != 1)
		return (0);
	return (1);
}

int	check_chars(char c)
{
	if (c == 'C')
		create_win()->c += 1;
	else if (c == 'P' && create_win()->p == 0)
		create_win()->p += 1;
	else if (c == 'E' && create_win()->e == 0)
		create_win()->e += 1;
	else if ((c != '1' && c != '0') || (c == 'P' && create_win()->p == 1)
		|| (c == 'E' && create_win()->e == 1))
		return (0);
	return (1);
}

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
	int	j;
	int	k;

	i = 0;
	j = ft_strlen(create_win()->map[i]);
	while (create_win()->map && create_win()->map[i])
	{
		k = j - 1;
		if (!create_win()->map[i + 1])
			j--;
		if ((int)ft_strlen(create_win()->map[i]) != j)
			return (0);
		while (--k >= 0)
		{
			if ((i == 0 || !create_win()->map[i + 1])
				&& create_win()->map[i][k] != '1')
				return (0);
			if ((k == 0 || k == (j - 2)) && create_win()->map[i][k] != '1')
				return (0);
			if (!check_chars(create_win()->map[i][k]))
				return (0);
		}
		i++;
	}
	return (valid_chars());
}

int	verify_map(char *filename)
{
	int		fd;
	int		cont;

	fd = open(filename, O_RDONLY);
	cont = is_empty(fd);
	if (!cont || cont < 3)
		return (0);
	create_win()->map = (char **)malloc(sizeof(char *) * (cont + 1));
	if (!create_win()->map)
		return (0);
	fd = open(filename, O_RDONLY);
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
