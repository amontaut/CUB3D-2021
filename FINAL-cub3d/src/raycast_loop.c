/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:05:25 by amontaut          #+#    #+#             */
/*   Updated: 2021/09/06 12:55:57 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 ** Draws from the first top px (top left) to the wall. 
 ** So basically Ceiling(lodev)
 */
void	top_to_drawstart(t_mlx *data, int *tmpstart)
{
	while (data->drawstart >= 0)
	{
		data->addr[data->drawstart * data->line_length / 4 + (int)data->x] \
			= (data->r_c * 256 * 256) + (data->g_c * 256) + data->b_c;
		data->drawstart--;
	}
	if (data->side == 0 && data->raydirx < 0)
		data->texdir = 0;
	if (data->side == 0 && data->raydirx >= 0)
		data->texdir = 1;
	if (data->side == 1 && data->raydiry < 0)
		data->texdir = 2;
	if (data->side == 1 && data->raydiry >= 0)
		data->texdir = 3;
	if (data->side == 0)
		data->wallx = data->posy + data->perpwalldist * data->raydiry;
	else
		data->wallx = data->posx + data->perpwalldist * data->raydirx;
	data->wallx -= floor((data->wallx));
	if (data->side == 0 && data->raydirx > 0)
		data->texx = data->text[data->texdir].width - data->texx - 1;
	if (data->side == 1 && data->raydiry < 0)
		data->texx = data->text[data->texdir].width - data->texx - 1;
	data->texpos = ((*tmpstart) - data->ry / 2 + data->lineheight \
			/ 2) * data->step;
}

/*
 ** Draws between the beggining of the wall to the end. 
 ** So basically walls and texture. (lodev)
 */
void	drawstart_to_drawend(t_mlx *data, int *tmpstart)
{
	while ((*tmpstart) <= data->drawend)
	{
		data->step = 1.0 * data->text[0].height / data->lineheight;
		data->texx = (int)(data->wallx * data->text[data->texdir].width);
		data->texy = (int)data->texpos & (data->text[data->texdir].height - 1);
		data->texpos += data->step;
		if ((*tmpstart) < data->ry && data->x < data->rx)
		{
			data->addr[(*tmpstart) * data->line_length / 4 + \
				(int)data->x] = data->text[data->texdir].addr[data->texy * \
				data->text[data->texdir].line_length / 4 + data->texx];
		}
		(*tmpstart)++;
	}
}

/*
 ** Draws from the bottom of the wall to the last px. So basically Floor.
 ** (lodev)
 */
void	drawend_to_bottom(t_mlx *data)
{
	while (++data->drawend < data->ry)
	{
		data->addr[data->drawend * data->line_length / 4 + (int)data->x] \
			= (data->r_f * 256 * 256) + (data->g_f * 256) + data->b_f;
	}
}

/*
 ** Digital Differential Analysis. (lodev)
 */
void	dda(t_mlx *data)
{
	while (data->hit == 0)
	{
		if (data->sidedistx < data->sidedisty)
		{
			data->sidedistx += data->deltadistx;
			data->mapx += data->stepx;
			data->side = 0;
		}
		else
		{
			data->sidedisty += data->deltadisty;
			data->mapy += data->stepy;
			data->side = 1;
		}
		if (data->worldmap[data->mapx][data->mapy] == '1')
			data->hit = 1;
	}
}

/*
 ** Raycasting loop. (lodev)
 */
void	boucle_raycast(t_mlx *data, int tmpstart)
{
	while (data->x < data->rx)
	{
		init_raycast_1(data);
		dda(data);
		if (data->side == 0)
			data->perpwalldist = ((double)data->mapx - data->posx \
					+ (1 - (double)data->stepx) / 2) / data->raydirx;
		else
			data->perpwalldist = ((double)data->mapy - data->posy \
					+ (1 - (double)data->stepy) / 2) / data->raydiry;
		data->lineheight = (int)data->ry / data->perpwalldist;
		data->drawstart = -data->lineheight / 2 + data->ry / 2;
		if (data->drawstart < 0)
			data->drawstart = 0;
		data->drawend = data->lineheight / 2 + data->ry / 2;
		if (data->drawend >= data->rx || data->drawend < 0)
			data->drawend = data->ry - 1;
		tmpstart = data->drawstart;
		data->drawend = data->ry - data->drawstart;
		top_to_drawstart(data, &tmpstart);
		drawstart_to_drawend(data, &tmpstart);
		drawend_to_bottom(data);
		data->x++;
	}
}
