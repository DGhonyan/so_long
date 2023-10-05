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

static void	free_exit(t_mlx *mlx, t_img *collect, char *errmsg)
{
	perror(errmsg);
	free_ptr_arr(mlx->map);
	mlx_destroy_image(mlx->mlx_ptr, mlx->walls->img);
	free(mlx->walls);
	mlx_destroy_image(mlx->mlx_ptr, mlx->floor->img);
	free(mlx->floor);
	free(collect);
	exit (EXIT_FAILURE);
}

t_img	*allocate_collect(t_mlx *mlx)
{
	t_img	*collect;

	collect = malloc(sizeof (*collect));
	if (!collect)
		free_exit(mlx, NULL, "Can't allocate collect");
	collect->img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			COLLECT_IMG, &(collect->w), &(collect->h));
	if (!collect->img)
		free_exit(mlx, collect, "Can't allocate collect img");
	return (collect);
}
