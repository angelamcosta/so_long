/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:15:07 by anlima            #+#    #+#             */
/*   Updated: 2023/02/13 13:30:24 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# ifndef  BUFFER_SIZE
#  define  BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
int		ft_clean(char *str);

typedef struct s_wins
{
	void	*mlx;
	void	*mlx_win;

}				t_wins;

typedef struct s_chars
{
	int		pos;
	void	*img;
	int		img_width;
	int		img_height;
}				t_chars;

t_wins	*create_win(void);

#endif