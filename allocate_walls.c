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

static void	free_and_exit(t_mlx *mlx, t_img *walls, char *errmsg)
{
	perror(errmsg);
	free_ptr_arr(mlx->map);
	free(walls);
	exit(EXIT_FAILURE);
}

t_img	*allocate_walls(t_mlx *mlx)
{
	t_img	*walls;

	walls = malloc(sizeof (*walls));
	if (!walls)
		free_and_exit(mlx, NULL, "failed to allocate walls");
	walls->img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			WALL_IMG, &(walls->w), &(walls->h));
	if (!walls->img)
		free_and_exit(mlx, walls, "failed to allocate wall img");
	return (walls);
}
