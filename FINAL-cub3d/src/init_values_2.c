/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:37:22 by amontaut          #+#    #+#             */
/*   Updated: 2021/09/06 12:56:48 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 ** init values for the raycast itself. (lodev)
 */
void	init_raycast_2(t_mlx *data)
{
	if (data->raydirx < 0)
	{
		data->stepx = -1;
		data->sidedistx = (data->posx - data->mapx) * data->deltadistx;
	}
	else
	{
		data->stepx = 1;
		data->sidedistx = (data->mapx + 1.0 - data->posx) * data->deltadistx;
	}
	if (data->raydiry < 0)
	{
		data->stepy = -1;
		data->sidedisty = (data->posy - data->mapy) * data->deltadisty;
	}
	else
	{
		data->stepy = 1;
		data->sidedisty = (data->mapy + 1.0 - data->posy) * data->deltadisty;
	}
}

/*
 ** init values for the raycast itself. (lodev)
 */
void	init_raycast_1(t_mlx *data)
{
	data->hit = 0;
	data->perpwalldist = 0;
	data->camerax = 2 * data->x / (double)data->rx - 1;
	data->raydirx = data->dirx + data->planex * data->camerax;
	data->raydiry = data->diry + data->planey * data->camerax;
	data->mapx = (int)data->posx;
	data->mapy = (int)data->posy;
	if (data->raydiry == 0)
		data->deltadistx = 0;
	else if (data->raydirx == 0)
		data->deltadistx = 1;
	else
		data->deltadistx = fabs(1 / data->raydirx);
	if (data->raydirx == 0)
		data->deltadisty = 0;
	else if (data->raydiry == 0)
		data->deltadisty = 1;
	else
		data->deltadisty = fabs(1 / data->raydiry);
	init_raycast_2(data);
}

/*
 ** init values before we put the map in a seperated str.
 */
void	init_malloc_strmap_remp_1(t_mlx *data,
		int *malloc_map, int *is_c, int *is_f)
{
	data->i = 0;
	data->iso = 0;
	data->iwe = 0;
	data->ino = 0;
	data->iea = 0;
	data->start_map = 0;
	data->tmp_start_map = 0;
	*malloc_map = 0;
	*is_c = 0;
	*is_f = 0;
}

/*
 ** Init for the position of the player (1/2)
 */
void	init_pos_1(t_mlx *data, int *check_ligne, double x, double y)
{
	if ((*check_ligne) == 1)
		ft_error(data, "Error, 2 players");
	data->dirx = x + 0.5;
	data->planey = y;
	data->map_add_1[data->i] = '0';
	(*check_ligne) = 1;
}

/*
 ** Init for the position of the player (2/2)
 */
void	init_pos_2(t_mlx *data, int *check_ligne, double x, double y)
{
	if ((*check_ligne) == 1)
		ft_error(data, "Error, 2 players");
	data->diry = x;
	data->planex = y;
	data->map_add_1[data->i] = '0';
	(*check_ligne) = 1;
}
