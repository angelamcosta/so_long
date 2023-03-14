/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:40:57 by anlima            #+#    #+#             */
/*   Updated: 2023/03/14 16:25:58 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		valid_chars(void);
void	check_chars(char c, int i, int j);
int		is_empty(int fd);
void	check_path(int i, int j);
int		is_valid(void);

int	valid_chars(void)
{
	if (create_map()->c < 1 || create_map()->p != 1 || create_map()->e != 1
		|| create_map()->other_chars > 0)
		return (0);
	check_path(create_map()->i, create_map()->j);
	if (create_map()->c == create_map()->c_count
		&& create_map()->e == create_map()->e_count
		&& create_map()->p == create_map()->p_count)
		return (1);
	return (0);
}

void	check_chars(char c, int i, int j)
{
	if (c == 'C')
		create_map()->c += 1;
	else if (c == 'P')
	{
		create_map()->p += 1;
		create_map()->i = i;
		create_map()->j = j;
	}
	else if (c == 'E')
		create_map()->e += 1;
	else if (c != '1' && c != '0')
		create_map()->other_chars += 1;
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

void	check_path(int i, int j)
{
	if (create_map()->map[i][j] == 'P' || create_map()->map[i][j] == 'E' ||
			create_map()->map[i][j] == 'C' || create_map()->map[i][j] == '0')
	{
		if (create_map()->map[i][j] == 'P')
		{
			create_map()->map[i][j] = 'p';
			create_map()->p_count += 1;
		}
		else if (create_map()->map[i][j] == 'E')
		{
			create_map()->map[i][j] = 'e';
			create_map()->e_count += 1;
		}
		else if (create_map()->map[i][j] == 'C')
		{
			create_map()->map[i][j] = 'c';
			create_map()->c_count += 1;
		}
		else if (create_map()->map[i][j] == '0')
			create_map()->map[i][j] = 'o';
		check_path(i + 1, j);
		check_path(i, j + 1);
		check_path(i - 1, j);
		check_path(i, j - 1);
	}
}

int	is_valid(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = ft_strlen(create_map()->map[i]);
	while (create_map()->map && create_map()->map[i])
	{
		k = j - 1;
		if (!create_map()->map[i + 1])
			j--;
		if ((int)ft_strlen(create_map()->map[i]) != j)
			return (0);
		while (--k >= 0)
		{
			if ((i == 0 || !create_map()->map[i + 1])
				&& create_map()->map[i][k] != '1')
				return (0);
			if ((k == 0 || k == (j - 2)) && create_map()->map[i][k] != '1')
				return (0);
			check_chars(create_map()->map[i][k], i, k);
		}
		i++;
	}
	return (valid_chars());
}
