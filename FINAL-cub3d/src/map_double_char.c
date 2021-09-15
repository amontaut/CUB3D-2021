/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_double_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:25:38 by amontaut          #+#    #+#             */
/*   Updated: 2021/09/06 12:53:31 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 ** If there are spaces at the end of a line in the map, 
 ** we will fill them with 1 and extend all other lines to
 ** the same length. This fct allows to malloc another str
 ** which will contain this new final map with 1 at the end
 ** of each line if necessary. It counts the malloc, and checks
 ** there is more than 1 line is the map, otherwise, error.
 */
void	calc_malloc_add_1(t_mlx *data)
{
	int	count_lenght;

	count_lenght = 0;
	data->i = 0;
	while (data->str_map[data->i])
	{
		count_lenght = 0;
		while (data->str_map[count_lenght + data->i] != '\n' \
				&& data->str_map[count_lenght + data->i] != '\0')
			count_lenght++;
		if (data->str_map[data->i] == '\n')
			data->final_height++;
		if (count_lenght > data->final_lenght)
			data->final_lenght = count_lenght;
		data->i++;
	}
	if (data->final_height <= 0)
		ft_error(data, "Error, only 1 line in the map");
	data->final_lenght = data->final_lenght - 1;
	data->map_add_1 = (char *)malloc(sizeof(char *) * \
			(data->final_height * data->final_lenght) + 1);
	if (data->map_add_1 == NULL)
		ft_error(data, "malloc map_add_1 failed");
}

/*
 ** Assigns the new final str map_add_1 with 1 at the end if necessary.
 */
void	assign_map_add1(t_mlx *data, int *i_map_add_1, int *count_height)
{
	int	tmp;

	tmp = 0;
	while (data->str_map[data->i] != '\n' && data->str_map[data->i] != '\0')
	{
		data->map_add_1[(*i_map_add_1)] = data->str_map[data->i];
		data->count_char++;
		data->i++;
		(*i_map_add_1)++;
	}
	tmp = data->i;
	while (data->count_char <= data->final_lenght)
	{
		data->map_add_1[(*i_map_add_1)] = '1';
		data->count_char++;
		(*i_map_add_1)++;
	}
	data->i = tmp;
	if (data->str_map[data->i] == '\n' || data->str_map[data->i] == '\0')
	{
		data->map_add_1[(*i_map_add_1)] = data->str_map[data->i];
		data->i++;
		(*i_map_add_1)++;
	}
	(*count_height)++;
}

/*
 ** Launch fct that will malloc a new str for the map with 1 at the end if
 ** necessary (if a line ends with spaces, all other lines will be the same
 ** length and spaces will be replaced by 1). The fct launches the malloc for 
 ** the new str, assigns it, check if there is more than 1 line in the map.
 */
void	fill_map_1(t_mlx *data)
{
	int	count_lenght;
	int	count_height;
	int	tmp_i_map;
	int	i_map_add_1;

	count_lenght = 0;
	data->final_lenght = 0;
	data->final_height = 0;
	data->i = 0;
	count_lenght = 0;
	calc_malloc_add_1(data);
	data->i = 0;
	count_height = 0;
	tmp_i_map = 0;
	i_map_add_1 = 0;
	while (count_height <= data->final_height)
	{
		data->count_char = 0;
		assign_map_add1(data, &i_map_add_1, &count_height);
	}
	data->map_add_1[i_map_add_1] = '\0';
}

/*
 ** Transfers the maps from the str to a double char table. 
 */
void	assign_in_table(t_mlx *data, int *i, int *h)
{
	while (data->i < data->final_lenght)
	{
		if (data->map_add_1[data->i] != '\n')
		{
			data->worldmap[(*h)][(*i)] = data->map_add_1[data->i];
			(*i)++;
			data->i++;
		}
		else
		{
			data->worldmap[(*h)][(*i)] = '\0';
			data->i++;
			(*i)++;
		}
	}
	if (data->map_add_1[data->i] != '\n')
	{
		data->worldmap[(*h)][(*i)] = data->map_add_1[data->i];
		data->i++;
		(*i)++;
	}
	else
		data->i++;
}

/*
 ** Launch the fct that will  malloc and assign the double char table
 ** that will contain the final map. The final map will be printed 
 ** just for info.
 */
void	assign_map_double_char(t_mlx *data)
{
	int	i;
	int	h;

	i = 0;
	h = 0;
	data->i = 0;
	data->final_height++;
	data->worldmap = (char **)malloc(sizeof(char *) * (data->final_height + 1));
	while (i <= data->final_height)
	{
		data->worldmap[i] = (char *)malloc(sizeof(char) * \
				data->final_lenght + 1);
		i++;
	}
	i = 0;
	while (h < data->final_height)
	{
		i = 0;
		while (i < data->final_lenght)
			assign_in_table(data, &i, &h);
		h++;
	}
	printf("\nMAP FINALE IS \n|%s|\n", data->map_add_1);
	ft_memdel((void *)&data->map_add_1);
}
