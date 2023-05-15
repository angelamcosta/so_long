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

void	free_ptr(void *ptr);
void	clean_mallocs(void);
void	free_ptr_ptr(void **ptr);

void	free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	free_ptr_ptr(void **ptr)
{
	if (ptr)
		free(ptr);
}

void	clean_mallocs(void)
{
	int	i;

	i = 0;
	while (create_map()->map && create_map()->map[i])
	{
		free_ptr(create_map()->map[i]);
		i++;
	}
	free_ptr_ptr((void **)create_map()->map);
}
