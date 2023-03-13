/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:15:07 by anlima            #+#    #+#             */
/*   Updated: 2023/03/13 21:30:17 by anlima           ###   ########.fr       */
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
# define CHAR_IMG "../assets/frog.xpm"
# define BCKGROUND "../assets/grass.xpm"

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	void	*img;
	void	*background;
	int		win_width;
	int		win_height;
	char	**map;
	int		c;
	int		p;
	int		e;
}				t_win;

t_win	*create_win(void);
int		events(int keycode);
void	create_background(void);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
int		ft_clean(char *str);
int		is_empty(int fd);
int		verify_map(char *file_name);

#endif