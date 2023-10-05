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

static void	free_exit(t_mlx *mlx, t_img *_exit, char *errmsg)
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
	free(mlx->player);
	free(_exit);
	exit (EXIT_FAILURE);
}

t_img	*allocate_exit(t_mlx *mlx)
{
	int		x;
	int		y;
	t_img	*exit;

	exit = malloc(sizeof (*exit));
	if (!exit)
		free_exit(mlx, NULL, "Can't allocate exit");
	exit->img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			EXIT_IMG, &(exit->w), &(exit->h));
	if (!exit->img)
		free_exit(mlx, exit, "Can't allocate exit img");
	x = get_exit_position(mlx->map).x;
	y = get_exit_position(mlx->map).y;
	exit->i = x;
	exit->j = y;
	exit->posx = (x * mlx->floor->w)
		+ ((mlx->floor->w / 2)) - (exit->w / 2);
	exit->posy = (y * mlx->floor->h)
		+ ((mlx->floor->h / 2)) - (exit->h / 2);
	return (exit);
}

t_pos	get_exit_position(char **map)
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
			if (map[i][j] == 'E')
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
