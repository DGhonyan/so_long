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

static void	free_exit(t_mlx *mlx, t_img *player, char *errmsg)
{
	perror(errmsg);
	free_ptr_arr(mlx->map);
	mlx_destroy_image(mlx->mlx_ptr, mlx->walls->img);
	free(mlx->walls);
	mlx_destroy_image(mlx->mlx_ptr, mlx->floor->img);
	free(mlx->floor);
	mlx_destroy_image(mlx->mlx_ptr, mlx->collect->img);
	free(mlx->collect);
	if (player->img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->player->img);
	if (player->img2)
		mlx_destroy_image(mlx->mlx_ptr, mlx->player->img2);
	free(player);
	exit (EXIT_FAILURE);
}

t_img	*allocate_player(t_mlx *mlx)
{
	int		x;
	int		y;
	t_img	*player;

	player = malloc(sizeof (*player));
	if (!player)
		free_exit(mlx, NULL, "Can't allocate player");
	player->img = NULL;
	player->img2 = NULL;
	player->img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			PLAYER_IMG, &(player->w), &(player->h));
	player->img2 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			PLAYER_IMG1, &(player->w), &(player->h));
	if (!player->img || !player->img2)
		free_exit(mlx, player, "Can't allocate player img");
	x = get_player_position(mlx->map).x;
	y = get_player_position(mlx->map).y;
	player->j = x;
	player->i = y;
	player->posx = (x * mlx->floor->w)
		+ ((mlx->floor->w / 2)) - (player->w / 2);
	player->posy = (y * mlx->floor->h)
		+ ((mlx->floor->h / 2)) - (player->h / 2);
	return (player);
}

t_pos	get_player_position(char **map)
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
			if (map[i][j] == 'P')
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
