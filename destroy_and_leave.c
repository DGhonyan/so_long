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

void	destroy_and_leave(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->exit->img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->walls->img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->collect->img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->floor->img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->player->img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->player->img2);
	mlx_destroy_image(mlx->mlx_ptr, mlx->enemy->img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->enemy->img2);
	free(mlx->exit);
	free(mlx->walls);
	free(mlx->floor);
	free(mlx->player);
	free(mlx->collect);
	free(mlx->enemy);
	free_ptr_arr(mlx->map);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
}
