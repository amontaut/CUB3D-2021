/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_CF.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:36:28 by amontaut          #+#    #+#             */
/*   Updated: 2021/09/06 12:40:26 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 ** Count the malloc for each string in which we'll put the C and F's path
 ** and check their syntaxes. If something is wrong, an error occurs. (1/3)
 */
void	check_path_cf_1(t_mlx *data, int *count_malloc)
{
	while (data->all_cub[data->i] == ' ')
		data->i++;
	if (!(data->all_cub[data->i] <= '9' && data->all_cub[data->i] >= '0'))
		ft_error(data, "Error, syntax C or F 1");
	while (data->all_cub[data->i] <= '9' && data->all_cub[data->i] >= '0')
	{
		(*count_malloc)++;
		data->i++;
	}
	while (data->all_cub[data->i] != ',')
	{
		if (data->all_cub[data->i] != ' ')
			ft_error(data, "Error, syntax C or F 2");
		data->i++;
	}
	if (data->all_cub[data->i] == ',')
	{
		(*count_malloc)++;
		data->i++;
	}
}

/*
 ** Count the malloc for each string in which we'll put the C and F's path
 ** and check their syntaxes. If something is wrong, an error occurs. (2/3)
 */
void	check_path_cf_2(t_mlx *data, int *count_malloc)
{
	while (data->all_cub[data->i] == ' ')
		data->i++;
	if (!(data->all_cub[data->i] <= '9' && data->all_cub[data->i] >= '0'))
		ft_error(data, "Error, syntax C or F 3");
	while (data->all_cub[data->i] <= '9' && data->all_cub[data->i] >= '0')
	{
		(*count_malloc)++;
		data->i++;
	}
	while (data->all_cub[data->i] != ',')
	{
		if (data->all_cub[data->i] != ' ')
			ft_error(data, "Error, syntax C or F 4");
		data->i++;
	}
	if (data->all_cub[data->i] == ',')
	{
		(*count_malloc)++;
		data->i++;
	}
}

/*
 ** Count the malloc for each string in which we'll put the C and F's path
 ** and check their syntaxes. If something is wrong, an error occurs. (3/3)
 */
void	check_path_cf_3(t_mlx *data, int *count_malloc)
{
	while (data->all_cub[data->i] == ' ')
		data->i++;
	if (!(data->all_cub[data->i] <= '9' && data->all_cub[data->i] >= '0'))
		ft_error(data, "Error, syntax C or F 5");
	while (data->all_cub[data->i] <= '9' && data->all_cub[data->i] >= '0')
	{
		(*count_malloc)++;
		data->i++;
	}
	while (data->all_cub[data->i] == ' ')
		data->i++;
	if (data->all_cub[data->i] != '\n')
		ft_error(data, "Error, syntax C or F, extra char");
}

/*
 ** Checks if the R G B values are between 0 and 255 thanks to the ints.
 */
void	check_int_cf(t_mlx *data, int R, int G, int B)
{
	if (!(R >= 0 && R <= 255))
		ft_error(data, "Error , R of the c or f is not incl between 0 and 255");
	if (!(G >= 0 && G <= 255))
		ft_error(data, "Error , G of the c or f is not incl between 0 and 255");
	if (!(B >= 0 && B <= 255))
		ft_error(data, "Error , B of the c or f is not incl between 0 and 255");
}
