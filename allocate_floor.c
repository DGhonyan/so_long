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

static void	free_exit(t_mlx *mlx, t_img *floor, char *errmsg)
{
	perror(errmsg);
	free_ptr_arr(mlx->map);
	mlx_destroy_image(mlx->mlx_ptr, mlx->walls->img);
	free(mlx->walls);
	free(floor);
	exit (EXIT_FAILURE);
}

t_img	*allocate_floor(t_mlx *mlx)
{
	t_img	*floor;

	floor = malloc(sizeof (*floor));
	if (!floor)
		free_exit(mlx, NULL, "Can't allocate floor");
	floor->img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			FLOOR_IMG, &(floor->w), &(floor->h));
	if (!floor->img)
		free_exit(mlx, floor, "Can't allocate floor img");
	return (floor);
}
