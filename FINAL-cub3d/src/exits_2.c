/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:38:15 by amontaut          #+#    #+#             */
/*   Updated: 2021/09/14 15:38:20 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 ** Used if the gnl goes wrong. 
 */
void	error_gnl(t_mlx *data)
{
	ft_error(data, "Error, problem with the gnl");
}

/*
 ** Destroys img of the mlx. Used when we exit the program and an img has been
 ** created. 
 */
void	destroy_img(t_mlx *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx_ptr, data->img);
	if (data->text[0].img)
		mlx_destroy_image(data->mlx_ptr, data->text[0].img);
	if (data->text[1].img)
		mlx_destroy_image(data->mlx_ptr, data->text[1].img);
	if (data->text[2].img)
		mlx_destroy_image(data->mlx_ptr, data->text[2].img);
	if (data->text[3].img)
		mlx_destroy_image(data->mlx_ptr, data->text[3].img);
}
