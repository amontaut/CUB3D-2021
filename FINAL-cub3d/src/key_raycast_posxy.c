/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_raycast_posxy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:25:22 by amontaut          #+#    #+#             */
/*   Updated: 2021/08/26 13:28:55 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 ** Actions when we press one of the key : ← → ESC W A S D
 ** Mooves the map or exit (for ESC) by setting values to 1.
 ** We have 2 different fct keypress and keyrelease so that we can press
 ** 2 keys at the same time and realease one of them. Usefull to 
 ** move the camera angle at the same time as W A S D.
 */
int	ft_keypress(int keycode, t_mlx *data)
{
	if (keycode == 119)
		data->up = 1;
	else if (keycode == 115)
		data->down = 1;
	else if (keycode == 100)
		data->right = 1;
	else if (keycode == 97)
		data->left = 1;
	if (keycode == 65363)
		data->camright = 1;
	else if (keycode == 65361)
		data->camleft = 1;
	else if (keycode == 65307)
		kill_all(data);
	return (0);
}

/*
 ** Actions when we release one of the key : ← → W A S D
 ** Mooves the map. Stop the action by setting vaues to 0.
 ** We have 2 different fct keypress and keyrelease so that we can press
 ** 2 keys at the same time and realease one of them. Usefull to
 ** move the camera angle at the same time as W A S D.
 */
int	ft_keyrelease(int keycode, t_mlx *data)
{
	if (keycode == 119)
		data->up = 0;
	else if (keycode == 115)
		data->down = 0;
	else if (keycode == 100)
		data->right = 0;
	else if (keycode == 97)
		data->left = 0;
	if (keycode == 65363)
		data->camright = 0;
	else if (keycode == 65361)
		data->camleft = 0;
	return (0);
}

/*
 ** Where all the raycast actually happens. (lodev)
 */
int	raycast(t_mlx *data)
{
	int	tmpstart;

	tmpstart = 0;
	up_down(data);
	right_left(data);
	cam_right(data);
	cam_left(data);
	data->x = 0;
	boucle_raycast(data, tmpstart);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	return (0);
}

/*
 ** While loop that will deter some values of the raycast 
 ** according to the orientation of the player in the map.
 */
void	while_data_posxy(t_mlx *data, int *check_ligne)
{
	if (data->map_add_1[data->i] == '\n' && (*check_ligne) == 0)
		data->posy = -2;
	if ((*check_ligne) == 0 && (data->map_add_1[data->i] != 'N' \
				|| data->map_add_1[data->i] != 'E' || \
				data->map_add_1[data->i] != 'S' || \
				data->map_add_1[data->i] != 'W'))
		data->posy++;
	if (data->map_add_1[data->i] == 'N')
		init_pos_1(data, check_ligne, -1, 0.66);
	else if (data->map_add_1[data->i] == 'S')
		init_pos_1(data, check_ligne, 1, -0.66);
	else if (data->map_add_1[data->i] == 'E')
		init_pos_2(data, check_ligne, 1, 0.66);
	else if (data->map_add_1[data->i] == 'W')
		init_pos_2(data, check_ligne, -1, -0.66);
	if (data->map_add_1[data->i] == '\n' && (*check_ligne) == 0)
		data->posx++;
	data->i++;
}

/*
 ** Launch the fct that will deter values for the raycast according
 ** to the player in the map and check there is a player
 */
void	deter_posxy(t_mlx *data)
{
	int	check_ligne;

	data->i = 0;
	check_ligne = 0;
	while (data->map_add_1[data->i])
		while_data_posxy(data, &check_ligne);
	if (check_ligne == 0)
		ft_error(data, "Error, no players");
}
