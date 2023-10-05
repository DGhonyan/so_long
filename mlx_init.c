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

#include "so_long.h"

static void	init(t_mlx *mlx)
{
	mlx->collect_count = get_count(mlx->map, 'C');

	mlx->walls = allocate(mlx, WALL_IMG);
	mlx->floor = allocate(mlx, FLOOR_IMG);
	mlx->collect = allocate(mlx, COLLECT_IMG);

	mlx->exit = allocate_pos(mlx, EXIT_IMG, NULL, 'E');
	mlx->player = allocate_pos(mlx, PLAYER_IMG1, PLAYER_IMG2, 'P');
	mlx->enemy = allocate_pos(mlx, ENEMY_IMG1, ENEMY_IMG2,'X');

	mlx->win_size_w = mlx->floor->w * ft_strlen(mlx->map[0]);
	mlx->win_size_h = mlx->floor->h * ptr_arr_len(mlx->map);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_size_w, mlx->win_size_h, "So long");

	draw(mlx, mlx->floor, 'F', -1);
	draw(mlx, mlx->walls, '1', -1);
	draw(mlx, mlx->collect, 'C', -1);
	draw(mlx, mlx->enemy, 'X', 0);

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->player->img, mlx->player->posx, mlx->player->posy);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->exit->img, mlx->exit->posx, mlx->exit->posy);
}

int	a(t_mlx *mlx)
{
	void		*texture;
	static int	i = 0;
	static int	index = 0;
	static int	p_index = 0;
	static int	player = 0;

	if (i % 1250 == 0)
	{
		draw(mlx, mlx->enemy, 'X', index % 2);
		index++;
	}
	if (player % 2500 == 0)
	{
		texture = (p_index % 2 == 0 ? mlx->player->img : mlx->player->img2);
		draw_single_floor(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		texture, mlx->player->posx, mlx->player->posy);
		p_index++;
	}
	i++;
	player++;
	return (0);
}

void	init_mlx(char *filename)
{
	t_mlx		mlx;

	mlx.mlx_ptr = mlx_init();
	perror_exit_cond("can't init mlx", !mlx.mlx_ptr);
	mlx.map = parse_map(filename);
	init(&mlx);
	mlx_key_hook(mlx.win_ptr, &key_hook, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, &hook, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &a, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
