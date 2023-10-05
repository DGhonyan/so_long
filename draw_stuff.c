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

static void	helper(t_mlx *mlx, int i, int j)
{
	mlx->collect->posx = (j * mlx->floor->w)
		+ ((mlx->floor->w / 2))
		- (mlx->collect->w / 2);
	mlx->collect->posy = (i * mlx->floor->h)
		+ ((mlx->floor->h / 2))
		- (mlx->collect->h / 2);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->collect->img,
		mlx->collect->posx, mlx->collect->posy);
}

void	draw_floor(t_mlx *mlx, char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1')
			{
				mlx_put_image_to_window(mlx->mlx_ptr,
					mlx->win_ptr, mlx->floor->img,
					j * (mlx->floor)->w, i * (mlx->floor)->h);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	draw_walls(t_mlx *mlx, char **map)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->walls->img,
					j * mlx->walls->w, i * mlx->walls->h);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	draw_collect(t_mlx *mlx, char **map)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				helper(mlx, i, j);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	draw_exit(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->exit->img,
		mlx->exit->posx, mlx->exit->posy);
}
