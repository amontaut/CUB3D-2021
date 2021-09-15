/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:36:58 by amontaut          #+#    #+#             */
/*   Updated: 2021/09/06 12:52:32 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 ** init all values to 0. (1/3)
 */
void	init_main_1(t_mlx *data)
{
	data->all_cub = NULL;
	data->str_map = NULL;
	data->map_add_1 = NULL;
	data->r_f = 0;
	data->g_f = 0;
	data->b_f = 0;
	data->r_c = 0;
	data->g_c = 0;
	data->b_c = 0;
	data->fd = 0;
	data->ret = 0;
	data->buff = NULL;
	data->line = 0;
	data->i = 0;
	data->malloc_no = 0;
	data->malloc_so = 0;
	data->malloc_ea = 0;
	data->malloc_we = 0;
	data->malloc_c = 0;
	data->malloc_f = 0;
	data->ino = 0;
	data->iso = 0;
	data->iwe = 0;
	data->iea = 0;
	data->count_char = 0;
}

/*
 ** init values. (2/3)
 */
void	init_main_2(t_mlx *data)
{
	data->planex = 0;
	data->planey = 0;
	data->rx = 500;
	data->ry = 500;
	data->img = NULL;
	data->mlx_win = NULL;
	data->movespeed = 0.007;
	data->rotspeed = 0.006;
	data->check_1_no = 0;
	data->check_1_so = 0;
	data->check_1_ea = 0;
	data->check_1_we = 0;
	data->check_1_c = 0;
	data->check_1_f = 0;
	data->up = 0;
	data->down = 0;
	data->right = 0;
	data->left = 0;
	data->camleft = 0;
	data->camright = 0;
	data->path_no = NULL;
	data->path_so = NULL;
	data->path_we = NULL;
	data->path_ea = NULL;
}

/*
 ** init all values to 0. (3/3)
 */
void	init_main_3(t_mlx *data)
{
	data->posx = 0;
	data->posy = 0;
	data->dirx = 0;
	data->diry = 0;
	data->text[0].img = NULL;
	data->text[1].img = NULL;
	data->text[2].img = NULL;
	data->text[3].img = NULL;
}

/*
 ** Continues init values for the mlx 2/2.
 */
void	init_mlx_2(t_mlx *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->rx, data->ry,
			"Raycasting at 42");
	data->text[0].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path_no, &(data->text[0].width),
			&(data->text[0].height));
	data->text[1].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path_so, &(data->text[1].width),
			&(data->text[1].height));
	data->text[2].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path_ea, &(data->text[2].width),
			&(data->text[2].height));
	data->text[3].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path_we, &(data->text[3].width),
			&(data->text[3].height));
}

/*
 ** init values for the mlx. 1/2
 */
void	init_mlx(t_mlx *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_error(data, "mlx init failed");
	mlx_get_screen_size(data->mlx_ptr, &data->real_rx, &data->real_ry);
	if (data->rx > data->real_rx)
		data->rx = data->real_rx;
	else
		data->rx = data->rx;
	if (data->ry > data->real_ry)
		data->ry = data->real_ry;
	else
		data->ry = data->ry;
	init_mlx_2(data);
}
