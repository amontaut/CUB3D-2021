/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 21:26:54 by amontaut          #+#    #+#             */
/*   Updated: 2021/09/06 12:45:20 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 ** Launch the mlx, the raycast, the mlx loop, keypress, keyrealse.
 */
void	launch_mlx(t_mlx *data, int *tmpstart)
{
	data->text[0].addr = (int *)mlx_get_data_addr(data->text[0].img,
			&data->text[0].bits_per_pixel,
			&data->text[0].line_length, &data->text[0].endian);
	data->text[1].addr = (int *)mlx_get_data_addr(data->text[1].img,
			&data->text[1].bits_per_pixel,
			&data->text[1].line_length, &data->text[1].endian);
	data->text[2].addr = (int *)mlx_get_data_addr(data->text[2].img,
			&data->text[2].bits_per_pixel,
			&data->text[2].line_length, &data->text[2].endian);
	data->text[3].addr = (int *)mlx_get_data_addr(data->text[3].img,
			&data->text[3].bits_per_pixel,
			&data->text[3].line_length, &data->text[3].endian);
	data->img = mlx_new_image(data->mlx_ptr, data->rx, data->ry);
	data->addr = (int *)mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->x = 0;
	boucle_raycast(data, *tmpstart);
	mlx_hook(data->mlx_win, 2, 1L << 0, ft_keypress, data);
	mlx_loop_hook(data->mlx_ptr, raycast, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, ft_keyrelease, data);
	mlx_hook(data->mlx_win, 33, 1L << 17, ft_exitx, data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	mlx_loop(data->mlx_ptr);
}

/*
 ** It all starts here 
 */
int	main(int argc, char **argv)
{
	int		tmpstart;
	t_mlx	data;

	tmpstart = 0;
	init_main_1(&data);
	init_main_2(&data);
	init_main_3(&data);
	check_nb_arg_gnl(&data, argc, argv);
	deter_malloc_text_cf(&data);
	fill_char_text_cf(&data);
	check_treat_rgb_c(&data);
	check_treat_rgb_f(&data);
	malloc_strmap_remp_1(&data);
	fill_map_1(&data);
	deter_posxy(&data);
	check_walls_are_1(&data);
	assign_map_double_char(&data);
	init_mlx(&data);
	if (data.text[0].img == NULL || data.text[1].img == NULL \
			|| data.text[2].img == NULL || data.text[3].img == NULL)
		exit_wrong_path(&data);
	launch_mlx(&data, &tmpstart);
	last_frees(&data);
	return (0);
}
