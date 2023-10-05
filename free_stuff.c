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

void	perror_exit_cond(char *errmsg, int cond)
{
	if (cond)
	{
		perror(errmsg);
		exit (EXIT_FAILURE);
	}
}

void	free_stuff_and_exit(char **arr, char *s, char *errmsg)
{
	if (errmsg)
		perror (errmsg);
	if (arr)
		free_ptr_arr(arr);
	free(s);
	exit (EXIT_FAILURE);
}

void	free_exit_cond(char **arr, char *s, char *errmsg, int cond)
{
	if (cond)
	{
		if (errmsg)
			perror (errmsg);
		if (arr)
			free_ptr_arr(arr);
		if (s)
			free(s);
		exit (EXIT_FAILURE);
	}
}
