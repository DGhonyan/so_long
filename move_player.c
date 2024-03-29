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

static void	check_tile(t_mlx *mlx)
{
	if (mlx->map[mlx->player->i][mlx->player->j] == 'C')
	{
		mlx->map[mlx->player->i][mlx->player->j] = '0';
		draw_single_floor(mlx);
	}
	if (mlx->map[mlx->player->i][mlx->player->j] == 'E'
		&& !get_count(mlx->map, 'C'))
		hook(mlx);
	if (mlx->map[mlx->player->i][mlx->player->j] == 'X')
	{
		ft_printf(RED "GAME OVER!\n" COLOR_RESET);
		hook (mlx);
	}
}

void	move(t_mlx *mlx, int change_x, int change_y, int posx, int posy)
{
	draw_single_floor(mlx);
	redraw_exit(mlx);
	mlx->player->posx += change_x;
	mlx->player->posy += change_y;
	mlx->player->j += posx;
	mlx->player->i += posy;
	check_tile(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->player->img, (mlx->player)->posx, (mlx->player)->posy);
}
