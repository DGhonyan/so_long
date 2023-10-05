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

//w = 13, a = 0, s = 1, d = 2
//left = 123 up = 126 down = 125 right = 124

static void	move_and_incr(int *count, t_mlx *mlx)
{
	char	*s;

	s = ft_itoa(*count);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->walls->img, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 0, 0, 0xffffff, s);
	free(s);
	*count += 1;
}	

static void	call_move(int keycode, t_mlx *mlx, int *count)
{
	if ((keycode == UP || keycode == UP_A)
		&& mlx->map[mlx->player->i - 1][mlx->player->j] != '1')
	{
		move_and_incr(count, mlx);
		move(mlx, 0, mlx->floor->h * -1, 0, -1);
	}
	else if ((keycode == DOWN || keycode == DOWN_A)
		&& mlx->map[mlx->player->i + 1][mlx->player->j] != '1')
	{
		move_and_incr(count, mlx);
		move(mlx, 0, mlx->floor->h, 0, 1);
	}
	else if ((keycode == LEFT || keycode == LEFT_A)
		&& mlx->map[mlx->player->i][mlx->player->j - 1] != '1')
	{
		move_and_incr(count, mlx);
		move(mlx, mlx->floor->w * -1, 0, -1, 0);
	}
	else if ((keycode == RIGHT || keycode == RIGHT_A)
		&& mlx->map[mlx->player->i][mlx->player->j + 1] != '1')
	{
		move_and_incr(count, mlx);
		move(mlx, mlx->floor->w, 0, 1, 0);
	}
}

int	key_hook(int keycode, t_mlx *mlx)
{
	static int	count = 1;

	if (keycode == ESC)
		hook(mlx);
	call_move(keycode, mlx, &count);
	return (0);
}

int	hook(t_mlx *mlx)
{
	(void)mlx;
	exit (EXIT_SUCCESS);
}
