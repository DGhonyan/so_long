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

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"

void	check_args(int argc, char *filename)
{
	if (argc < 2)
	{
		ft_printf(CYAN "Usage: ./so_long maps/map[num].ber\n" COLOR_RESET);
		exit (EXIT_FAILURE);
	}
	if (argc > 2)
	{
		ft_printf(RED "Too many arguments\n" COLOR_RESET);
		exit (EXIT_FAILURE);
	}
	if (check_file_extension(filename))
	{
		ft_printf(RED "Wrong file extension, must be .ber\n" COLOR_RESET);
		exit (EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	char	**map;

	check_args(argc, argv[1]);
	map = parse_map(argv[1]);
	free_exit_cond(map, NULL, NULL, !map_check(map));
	free_ptr_arr(map);
	init_mlx(argv[1]);
}
