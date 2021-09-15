/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_path_TCF.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:00:21 by amontaut          #+#    #+#             */
/*   Updated: 2021/09/06 12:43:47 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 ** Fills the str with the path of the textures, without spaces (just the path).
 */
void	fill_path_text(t_mlx *data, int *j, char *name, char **path)
{
	if (data->all_cub[data->i] == name[0] && data->all_cub[data->i + 1] == \
			name[1])
	{
		data->i = data->i + 2;
		while (data->all_cub[data->i] != '\n')
		{
			if (data->all_cub[data->i] != ' ')
			{
				(*path)[(*j)] = data->all_cub[data->i];
				(*j)++;
			}
			data->i++;
		}
	}
	(*path)[(*j)] = '\0';
}

/*
 ** Puts the number of the R and G colors in seperated ints
 */
void	fill_path_rg_cf(t_mlx *data, int *R, int *G)
{
	while (!(data->all_cub[data->i] <= '9' && data->all_cub[data->i] >= '0'))
		data->i++;
	while (data->all_cub[data->i] <= '9' && data->all_cub[data->i] >= '0')
	{
		(*R) = (*R) * 10 + data->all_cub[data->i] - '0';
		data->i++;
	}
	while (data->all_cub[data->i] != ',')
		data->i++;
	if (data->all_cub[data->i] == ',')
		data->i++;
	while (!(data->all_cub[data->i] <= '9' && data->all_cub[data->i] >= '0'))
		data->i++;
	while (data->all_cub[data->i] <= '9' && data->all_cub[data->i] >= '0')
	{
		(*G) = (*G) * 10 + data->all_cub[data->i] - '0';
		data->i++;
	}
}

/*
 ** Puts the number of the B color in an int
 */
void	fill_path_b_cf(t_mlx *data, int *B)
{
	while (data->all_cub[data->i] != ',')
		data->i++;
	if (data->all_cub[data->i] == ',')
		data->i++;
	while (!(data->all_cub[data->i] <= '9' && data->all_cub[data->i] >= '0') \
			&& data->all_cub[data->i] != '\n')
		data->i++;
	while (data->all_cub[data->i] <= '9' && data->all_cub[data->i] >= '0')
	{
		(*B) = (*B) * 10 + data->all_cub[data->i] - '0';
		data->i++;
	}
}

/*
 ** Puts the number of the R, G, B colors of C in seperated ints
 */
void	fill_path_c(t_mlx *data, int *R, int *G, int *B)
{
	if (data->all_cub[data->i] == 'C')
	{
		data->i++;
		fill_path_rg_cf(data, R, G);
		fill_path_b_cf(data, B);
	}
}

/*
 ** Puts the number of the R, G, B colors of F in seperated ints
 */
void	fill_path_f(t_mlx *data, int *R, int *G, int *B)
{
	if (data->all_cub[data->i] == 'F')
	{
		data->i++;
		fill_path_rg_cf(data, R, G);
		fill_path_b_cf(data, B);
	}
}
