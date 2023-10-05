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

static int	map_len_check(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	while (map[i])
	{
		if (i == 0)
			len = ft_strlen(map[i]);
		if (len != ft_strlen(map[i]))
		{
			ft_printf(RED "Map must be a rectangle\n" COLOR_RESET);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	first_last(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	middle(char *s)
{
	return (s[0] == '1' && s[ft_strlen(s) - 1] == '1');
}

static int	map_chars_check(char **map)
{
	if (!is_allowed(map, "01PECX"))
	{
		ft_printf(RED "Invalid characters in the map\n" COLOR_RESET);
		return (0);
	}
	return (at_least_one(map));
}

int	map_check(char **map)
{
	int	i;
	int	len;

	i = 0;
	if (!map_chars_check(map) || !map_len_check(map))
		return (0);
	len = ptr_arr_len(map);
	while (map[i])
	{
		if (((i == 0 || i == len - 1) && !first_last(map[i]))
			|| ((i > 0 && i < len - 1) && !middle(map[i])))
		{
			ft_printf(RED "Map isn't surrounded by walls\n" COLOR_RESET);
			return (0);
		}
		i++;
	}
	return (1);
}
