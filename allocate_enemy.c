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

static void	free_exit(t_mlx *mlx, t_img *enemy, char *errmsg)
{
	perror(errmsg);
	free_ptr_arr(mlx->map);
	mlx_destroy_image(mlx->mlx_ptr, mlx->walls->img);
	free(mlx->walls);
	mlx_destroy_image(mlx->mlx_ptr, mlx->floor->img);
	free(mlx->floor);
	mlx_destroy_image(mlx->mlx_ptr, mlx->collect->img);
	free(mlx->collect);
	mlx_destroy_image(mlx->mlx_ptr, mlx->player->img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->player->img2);
	free(mlx->player);
	if (enemy->img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->enemy->img);
	if (enemy->img2)
		mlx_destroy_image(mlx->mlx_ptr, mlx->enemy->img2);
	free(enemy);
	exit (EXIT_FAILURE);
}

t_img	*allocate_enemy(t_mlx *mlx)
{
	int		x;
	int		y;
	t_img	*enemy;

	enemy = malloc(sizeof (*enemy));
	if (!enemy)
		free_exit(mlx, NULL, "Can't allocate enemy");
	enemy->img = NULL;
	enemy->img2 = NULL;
	enemy->img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			ENEMY_IMG, &(enemy->w), &(enemy->h));
	enemy->img2 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"images/X2.xpm", &(enemy->w), &(enemy->h));
	if (!enemy->img || !enemy->img2)
		free_exit(mlx, enemy, "Can't allocate enemy img");
	x = get_enemy_position(mlx->map).x;
	y = get_enemy_position(mlx->map).y;
	enemy->j = x;
	enemy->i = y;
	enemy->posx = (x * mlx->floor->w)
		+ ((mlx->floor->w / 2)) - (enemy->w / 2);
	enemy->posy = (y * mlx->floor->h)
		+ ((mlx->floor->h / 2)) - (enemy->h / 2);
	return (enemy);
}

t_pos	get_enemy_position(char **map)
{
	int		i;
	int		j;
	t_pos	pos;

	i = 1;
	pos.x = 0;
	pos.y = 0;
	while (map[i + 1])
	{
		j = 1;
		while (map[i][j + 1])
		{
			if (map[i][j] == 'X')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

void	draw_enemy(t_mlx *mlx, int img)
{
	int		i;
	int		j;
	void	*s;

	i = 0;
	s = mlx->enemy->img;
	if (img)
		s = mlx->enemy->img2;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'X')
			{
				mlx_put_image_to_window(mlx->mlx_ptr,
					mlx->win_ptr, s,
					j * (mlx->enemy)->w, i * (mlx->enemy)->h);
			}
			j++;
		}
		i++;
	}
}
