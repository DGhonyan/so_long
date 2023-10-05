/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:47:41 by dghonyan          #+#    #+#             */
/*   Updated: 2022/05/21 19:47:46 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# define PLAYER_IMG "images/P1.xpm"
# define PLAYER_IMG1 "images/P2.xpm"
# define PLAYER_IMG2 "images/P3.xpm"
# define PLAYER_IMG3 "images/P4.xpm"
# define WALL_IMG "images/1.xpm"
# define FLOOR_IMG "images/0.xpm"
# define COLLECT_IMG "images/C.xpm"
# define EXIT_IMG "images/E.xpm"
# define ENEMY_IMG "images/X1.xpm"

// # define ESC 65307

//MAC
# define ESC 53

//LINUX
// # define UP 119
// # define DOWN 115
// # define LEFT 97
// # define RIGHT 100

//MACw
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2

//LINUX
// # define UP_A 65362
// # define DOWN_A 65364
// # define LEFT_A 65361
// # define RIGHT_A 65363

//MAC
# define UP_A 126
# define DOWN_A 125
# define LEFT_A 123
# define RIGHT_A 124

# include "mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include "colors.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_pos {
	int	x;
	int	y;
}	t_pos;

typedef struct s_chars {
	int	p;
	int	c;
	int	e;
	int	x;
}	t_chars;

typedef struct s_img {
	void	*img;
	void	*img2;
	int		w;
	int		h;
	int		i;
	int		j;
	int		posx;
	int		posy;
}	t_img;

typedef struct s_mlx {
	t_img		*floor;
	t_img		*collect;	
	t_img		*walls;
	t_img		*exit;
	t_img		*player;
	t_img		*enemy;
	char		**map;
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_size_w;
	int			win_size_h;
	int			collect_count;
}	t_mlx;

int		is_allowed(char **map, char *allowed);
int		at_least_one(char **s);
int		check_file_extension(char *s);
int		map_check(char **map);
int		get_count(char **map, char c);
int		get_count_reverse(char **map, char c);
int		first_where(t_img **floor, int i, int j);
int		key_hook(int keycode, t_mlx *mlx);
int		hook(t_mlx *mlx);
// void	helper(t_mlx *mlx, int i, int j);

char	**parse_map(char *filename);

void	mlx_init_stuff(char *filename);
void	perror_exit_cond(char *errmsg, int cond);
void	free_stuff_and_exit(char **arr, char *s, char *errmsg);
void	do_things(t_mlx *mlx);
void	redraw_exit(t_mlx *mlx);
void	draw_floor(t_mlx *mlx, char **map);
void	draw_single_floor(t_mlx *mlx);
void	draw_exit(t_mlx *mlx);
void	draw_enemy(t_mlx *mlx, int i);
void	draw_walls(t_mlx *mlx, char **map);
void	draw_collect(t_mlx *mlx, char **map);
void	move_up(t_mlx *mlx);
void	move_down(t_mlx *mlx);
void	move_left(t_mlx *mlx);
void	move_right(t_mlx *mlx);
void	destroy_and_leave(t_mlx *mlx);
void	free_exit_cond(char **arr, char *s, char *errmsg, int cond);

t_pos	get_player_position(char **map);
t_pos	get_exit_position(char **map);
t_pos	get_enemy_position(char **map);

t_img	*allocate_player(t_mlx *mlx);
t_img	*allocate_exit(t_mlx *mlx);
t_img	*allocate_walls(t_mlx *mlx);
t_img	*allocate_collect(t_mlx *mlx);
t_img	*allocate_floor(t_mlx *mlx);
t_img	*allocate_enemy(t_mlx *mlx);

#endif
