/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:05:39 by amontaut          #+#    #+#             */
/*   Updated: 2021/09/06 12:53:31 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 ** Last frees to exit properly when everything goes well. 
 */
void	last_frees(t_mlx *data)
{
	ft_memdel((void *)&data->path_no);
	ft_memdel((void *)&data->path_so);
	ft_memdel((void *)&data->path_ea);
	ft_memdel((void *)&data->path_we);
	ft_memdel((void *)&data->mlx_win);
	ft_memdel((void *)&data->img);
	ft_memdel((void *)&data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_display(data->mlx_ptr);
}

/*
 ** Called everytime there's an error to exit properly and displays a 
 ** msg corresponding to the error. There are about 30 errors possible, 
 ** including : a malloc fails, parsing errors (problem with the texture's 
 ** path  or the map or the C or F 
 ** in the .cub...).
 */
int	ft_error(t_mlx *data, char *msg)
{
	printf("\n%s\n", msg);
	ft_memdel((void *)&data->path_no);
	ft_memdel((void *)&data->path_so);
	ft_memdel((void *)&data->path_ea);
	ft_memdel((void *)&data->path_we);
	ft_memdel((void *)&data->str_map);
	ft_memdel((void *)&data->map_add_1);
	ft_memdel((void *)&data->all_cub);
	exit(-1);
}

/*
 ** Called when we exit the program by pressing ESC/clicking on the red cross. 
 ** Frees and destroys what need to be destroyed.
 */
int	kill_all(t_mlx *data)
{
	int	i;

	i = 0;
	ft_memdel((void *)&data->path_no);
	ft_memdel((void *)&data->path_so);
	ft_memdel((void *)&data->path_ea);
	ft_memdel((void *)&data->path_we);
	while (i <= data->final_height)
	{
		ft_memdel((void *)&data->worldmap[i]);
		i++;
	}
	ft_memdel((void *)&data->worldmap);
	destroy_img(data);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	ft_memdel((void *)&data->mlx_ptr);
	exit(-1);
}

/*
 ** Called when we exit the program because one of the texture's path is wrong in
 ** the .cub file. 
 ** Frees and destroys what needs to be destroyed.
 */
int	exit_wrong_path(t_mlx *data)
{
	int	i;

	i = 0;
	printf("Error, wrong texture's path\n");
	ft_memdel((void *)&data->path_no);
	ft_memdel((void *)&data->path_so);
	ft_memdel((void *)&data->path_ea);
	ft_memdel((void *)&data->path_we);
	destroy_img(data);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	ft_memdel((void *)&data->mlx_ptr);
	while (i <= data->final_height)
	{
		ft_memdel((void *)&data->worldmap[i]);
		i++;
	}
	ft_memdel((void *)&data->worldmap);
	exit(-1);
}

/*
 ** Called when we exit the program by clicking on the red cross
 ** or on ESC.
 */
int	ft_exitx(t_mlx *data)
{
	kill_all(data);
	exit(-1);
}
