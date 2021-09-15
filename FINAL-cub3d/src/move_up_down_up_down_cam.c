/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_down_up_down_cam.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:44:31 by amontaut          #+#    #+#             */
/*   Updated: 2021/09/06 12:53:31 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 ** Thanks to the fct keypress we set the values up (key W) and down (key S) 
 ** to 1 if needed. The map can now move by changing the values of 
 ** posx and poxy. (lodev)
 */
void	up_down(t_mlx *data)
{
	if (data->up == 1)
	{
		if (data->worldmap[(int)(data->posx + data->dirx \
					* data->movespeed)][(int)(data->posy)] == '0')
			data->posx += data->dirx * data->movespeed;
		if (data->worldmap[(int)(data->posx)][(int)(data->posy \
					+ data->diry * data->movespeed)] == '0')
			data->posy += data->diry * data->movespeed;
	}
	if (data->down == 1)
	{
		if (data->worldmap[(int)(data->posx - data->dirx \
					* data->movespeed)][(int)(data->posy)] == '0')
			data->posx -= data->dirx * data->movespeed;
		if (data->worldmap[(int)(data->posx)][(int)(data->posy - data->diry \
					* data->movespeed)] == '0')
			data->posy -= data->diry * data->movespeed;
	}
}

/*
 ** Thanks to the fct keypress we set the values right (key D) and 
 ** left (key A) to 1 if needed. The map can now move by changing 
 ** the values of posx and poxy. (lodev)
 */
void	right_left(t_mlx *data)
{
	if (data->right == 1)
	{
		if (data->worldmap[(int)(data->posx + data->diry * data->movespeed)] \
		[(int)data->posy] == '0')
			data->posx += data->diry * data->movespeed;
		if (data->worldmap[(int)data->posx][(int)(data->posy - data->dirx * \
			data->movespeed)] == '0')
			data->posy -= data->dirx * data->movespeed;
	}
	if (data->left == 1)
	{
		if (data->worldmap[(int)(data->posx - data->diry * data->movespeed)] \
		[(int)(data->posy)] == '0')
			data->posx -= data->diry * data->movespeed;
		if (data->worldmap[(int)(data->posx)][(int)(data->posy + data->dirx * \
			data->movespeed)] == '0')
			data->posy += data->dirx * data->movespeed;
	}
}

/*
 ** Thanks to the fct keypress we set the value cam right (key →) to 1 
 ** if needed. The map can now move by changing the values of dirx, 
 ** diry, planex, planey. (lodev)
 */
void	cam_right(t_mlx *data)
{
	if (data->camright == 1)
	{
		data->olddirx = data->dirx;
		data->dirx = data->dirx * cos(-data->rotspeed) - data->diry * \
					 sin(-data->rotspeed);
		data->diry = data->olddirx * sin(-data->rotspeed) + data->diry * \
					 cos(-data->rotspeed);
		data->oldplanex = data->planex;
		data->planex = data->planex * cos(-data->rotspeed) - data->planey * \
					   sin(-data->rotspeed);
		data->planey = data->oldplanex * sin(-data->rotspeed) + data->planey * \
					   cos(-data->rotspeed);
	}
}

/*
 ** Thanks to the fct keypress we set the value cam left (key ←) to 1 if needed. 
 **The map can now move by changing the values of dirx, diry, planex, planey. 
 ** (lodev)
 */
void	cam_left(t_mlx *data)
{
	if (data->camleft == 1)
	{
		data->olddirx = data->dirx;
		data->dirx = data->dirx * cos(data->rotspeed) - data->diry * \
					 sin(data->rotspeed);
		data->diry = data->olddirx * sin(data->rotspeed) + data->diry * \
					 cos(data->rotspeed);
		data->oldplanex = data->planex;
		data->planex = data->planex * cos(data->rotspeed) - data->planey * \
					   sin(data->rotspeed);
		data->planey = data->oldplanex * sin(data->rotspeed) + data->planey * \
					   cos(data->rotspeed);
	}
}
