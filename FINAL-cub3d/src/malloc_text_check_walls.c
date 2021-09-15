/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_text_check_walls.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:25:30 by amontaut          #+#    #+#             */
/*   Updated: 2021/09/06 12:50:13 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 ** Count the malloc for each string in which we'll put the texture's path
 ** and check that there is only 1 path/info for 1 text.
 */
void	count_malloc_path_text(t_mlx *data, int *count_malloc, char *name,
		int *check_double)
{
	if (data->all_cub[data->i] == name[0] && data->all_cub[data->i + 1] \
			== name[1])
	{
		if ((*check_double) != 1)
		{
			data->i = data->i + 2;
			(*check_double) = 1;
			while (data->all_cub[data->i] != '\n')
			{
				if (data->all_cub[data->i] != ' ')
					(*count_malloc)++;
				data->i++;
			}
		}
		else
			ft_error(data, "Error, more than 1 text def");
	}
}

/*
 ** Will count the malloc for each strings for the C and F and check 
 ** their syntaxes.
 */
void	count_malloc_cf(t_mlx *data, int *count_malloc, char c,
		int *check_double)
{
	if (data->all_cub[data->i] == c)
	{
		data->i++;
		if ((*check_double) != 1)
		{
			(*check_double) = 1;
			check_path_cf_1(data, count_malloc);
			check_path_cf_2(data, count_malloc);
			check_path_cf_3(data, count_malloc);
		}
		else
			ft_error(data, "Error, more than 1 C or 1 F are def");
	}
}

/*
 ** Will launch fct to count mallocs for each str that will store
 ** the paths (NO, SO, WE, EA) and C F + checks (double, syntaxe).
 */
void	deter_malloc_text_cf(t_mlx *data)
{
	while (data->all_cub[data->i])
	{
		while (data->all_cub[data->i] == ' ')
			data->i++;
		count_malloc_path_text(data, &data->malloc_no, "NO", &data->check_1_no);
		count_malloc_path_text(data, &data->malloc_so, "SO", &data->check_1_so);
		count_malloc_path_text(data, &data->malloc_ea, "EA", &data->check_1_ea);
		count_malloc_path_text(data, &data->malloc_we, "WE", &data->check_1_we);
		count_malloc_cf(data, &data->malloc_c, 'C', &data->check_1_c);
		count_malloc_cf(data, &data->malloc_f, 'F', &data->check_1_f);
		data->i++;
	}
	data->path_no = (char *)malloc(data->malloc_no * (sizeof(char) + 1));
	if (data->path_no == NULL)
		ft_error(data, "Malloc path_no failed");
	data->path_so = (char *)malloc(data->malloc_so * (sizeof(char) + 1));
	if (data->path_so == NULL)
		ft_error(data, "Malloc path_so failed");
	data->path_ea = (char *)malloc(data->malloc_ea * (sizeof(char) + 1));
	if (data->path_ea == NULL)
		ft_error(data, "Malloc path_ea failed");
	data->path_we = (char *)malloc(data->malloc_we * (sizeof(char) + 1));
	if (data->path_we == NULL)
		ft_error(data, "Malloc path_we failed");
}

/*
 ** Checks if the left and right walls are continuous.
 */
void	right_left_walls(t_mlx *data, int *nb_tour)
{
	int	count_lenght;

	count_lenght = 0;
	while (data->str_map[data->i])
	{
		if (data->str_map[count_lenght + data->i + 1] == '\n' \
				|| data->str_map[count_lenght + data->i + 1] == '\0')
			if (data->str_map[count_lenght + data->i] == '0')
				ft_error(data, "Error, incorrect last line");
		data->i++;
	}
	while ((*nb_tour) <= (data->final_height - 1))
	{
		if (data->map_add_1[(data->final_lenght + 1) *(*nb_tour)] != '1')
			ft_error(data, "Error, a line doesn't start by a wall");
		if (data->map_add_1[((data->final_lenght + 1) * ((*nb_tour))) \
				+ (data->final_lenght - 1)] != '1')
			ft_error(data, "Error, incorrect last line");
		(*nb_tour)++;
	}
}

/*
 ** Check if the map is surrounded by continuous walls.
 */
void	check_walls_are_1(t_mlx *data)
{
	int	tmp_final_length;
	int	nb_tour;
	int	len_ajout_1;
	int	av_der;

	tmp_final_length = data->final_lenght;
	while (tmp_final_length)
	{
		if (data->map_add_1[tmp_final_length] != '1')
			ft_error(data, "Error, 1st line is not a continuous wall");
		tmp_final_length--;
	}
	nb_tour = 0;
	data->final_lenght = data->final_lenght + 1;
	data->i = 0;
	right_left_walls(data, &nb_tour);
	len_ajout_1 = ft_strlen(data->map_add_1) - 1;
	av_der = len_ajout_1 - data->final_lenght + 1;
	while (len_ajout_1 >= av_der)
	{
		if (data->map_add_1[len_ajout_1] != '1')
			ft_error(data, "Error, last line is not a continuous wall");
		len_ajout_1--;
	}
	ft_memdel((void *)&data->str_map);
}
