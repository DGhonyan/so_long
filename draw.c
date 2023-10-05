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

void	draw(t_mlx *mlx, t_img *img, char character_symbol, int anim) // symbol F for floor
{
	int		i;
	int		j;
	char	**map;
	void	*texture;

	i = 0;
	map = mlx->map;
	if (anim < 0)
		texture = img->img;
	else
		texture = (anim % 2 == 0 ? img->img : img->img2);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (character_symbol == 'F' || map[i][j] == character_symbol)
			{
				if (character_symbol == 'C')
					helper(mlx, i, j);
				else
					mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, texture, j * (img->w), i * (img->h));
			}
			j++;
		}
		i++;
	}
}

void	draw_single_floor(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->floor->img,
		mlx->player->j * mlx->floor->w,
		mlx->player->i * mlx->floor->h);
}

void	redraw_exit(t_mlx *mlx)
{
	if (mlx->map[mlx->player->i][mlx->player->j] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->exit->img, mlx->exit->posx, mlx->exit->posy);
}
