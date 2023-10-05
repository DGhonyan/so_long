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

t_img	*allocate(t_mlx *mlx, char *texture)
{
	t_img	*img;

	img = malloc(sizeof (*img));
	if (!img)
		exit(EXIT_FAILURE);
	img->img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			texture, &(img->w), &(img->h));
	if (!img->img)
		exit(EXIT_FAILURE);
	return (img);
}

t_img	*allocate_pos(t_mlx *mlx, char *texture1, char *texture2, char character_symbol)
{
	int		x;
	int		y;
	t_img	*img;

	img = malloc(sizeof (*img));
	if (!img)
		exit(1);
	img->img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			texture1, &(img->w), &(img->h));
	if (texture2)
		img->img2 = mlx_xpm_file_to_image(mlx->mlx_ptr,
				texture2, &(img->w), &(img->h));
	if (!img->img || (texture2 && !img->img2))
		exit(1);
	x = get_position(mlx->map, character_symbol).x;
	y = get_position(mlx->map, character_symbol).y;
	img->j = x;
	img->i = y;
	img->posx = (x * mlx->floor->w)
		+ ((mlx->floor->w / 2)) - (img->w / 2);
	img->posy = (y * mlx->floor->h)
		+ ((mlx->floor->h / 2)) - (img->h / 2);
	return (img);
}

t_pos	get_position(char **map, char c)
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
			if (map[i][j] == c)
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