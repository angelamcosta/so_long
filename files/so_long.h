/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:15:07 by anlima            #+#    #+#             */
/*   Updated: 2023/05/15 14:12:47 by anlima           ###   ########.fr       */
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
# define  BUFFER_SIZE 24
# define PIXEL_SIZE 32
# define CHAR_IMG "../assets/pidgeon1.xpm"
# define COLLECTIBLE "../assets/crackers.xpm"
# define BCKGROUND "../assets/grass.xpm"
# define EXIT "../assets/exit.xpm"
# define WALL "../assets/wall.xpm"
# define WIN_NAME "cozy joguinho"

typedef struct s_win
{
	int		x;
	int		y;
	int		c;
	int		win_width;
	int		win_height;
	int		moves;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*background;
	void	*collectible;
	void	*exit;
	void	*wall;
}				t_win;

typedef struct s_map
{
	int		c;
	int		p;
	int		e;
	int		other_chars;
	int		c_count;
	int		e_count;
	int		i;
	int		j;
	int		x;
	int		y;
	char	**map;
}				t_map;

void	free_ptr(void *ptr);
void	clean_mallocs(void);
void	free_ptr_ptr(void **ptr);
void	ft_putnbr(long nbr);
void	create_background(void);
void	put_items(void);
void	collect_itens(void);
t_win	*create_win(void);
t_map	*create_map(void);
int		events_keys(int keycode);
int		close_win(int keycode);
void	key_events(int i, int j, int *val, int isSum);
int		print_moves(void);
int		moved(void);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
int		ft_clean(char *str);
char	*get_next_line(int fd);
int		valid_chars(void);
void	check_chars(char c, int i, int j);
int		is_empty(int fd);
void	check_path(int i, int j);
int		is_valid(void);
int		verify_map(char *file_name);

#endif