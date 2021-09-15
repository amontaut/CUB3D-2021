/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:25:54 by amontaut          #+#    #+#             */
/*   Updated: 2021/09/13 21:45:56 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 ** To isolate the map from our all_cub, we need to know
 ** where it starts. This fct gives us the i where the map
 ** starts in the all cub.
 */
void	count_i(t_mlx *data, int *is_path, char *name)
{
	if (ft_strlen(name) == 2)
	{
		if (data->all_cub[data->i] == name[0] && \
				data->all_cub[data->i + 1] == name[1])
		{
			(*is_path) = 1;
			while (data->all_cub[data->i] != '\n')
				data->i++;
		}
	}
	else if (ft_strlen(name) == 1)
	{
		if (data->all_cub[data->i] == name[0])
		{
			(*is_path) = 1;
			while (data->all_cub[data->i] != '\n')
				data->i++;
		}
	}
}

/*
 ** Calc the malloc to isolate the map and checks if a map
 ** is def and def in last.
 */
void	calc_malloc_fill1(t_mlx *data, int *malloc_map)
{
	data->start_map = data->tmp_start_map;
	while (data->all_cub[data->start_map] == ' ' \
			|| data->all_cub[data->start_map] == '\n')
		data->start_map++;
	data->tmp_start_map = data->start_map;
	while (data->all_cub[data->start_map])
	{
		(*malloc_map)++;
		data->start_map++;
	}
	if ((*malloc_map) == 0)
		ft_error(data, "Error, no map def in the .cub file \
				OR map not def in last");
	while (data->all_cub[data->start_map] == ' ' \
			|| data->all_cub[data->start_map] == '\n' \
			|| data->all_cub[data->start_map] == '\0')
	{
		data->start_map--;
		(*malloc_map)--;
	}
}

/*
 ** Assigns the map (spaces have alredy been remplaced by 1)
 ** in a unique str str_map.
 */
void	assign_map_fill1(t_mlx *data, int malloc_map)
{
	data->i = 0;
	data->str_map = (char *)(malloc((sizeof(char *) * malloc_map) + 1));
	if (data->str_map == NULL)
		ft_error(data, "malloc str_map failed");
	while (data->tmp_start_map <= data->start_map)
	{
		data->str_map[data->i] = data->all_cub[data->tmp_start_map];
		data->tmp_start_map++;
		data->i++;
	}
	data->str_map[data->i] = '\0';
	ft_memdel((void *)&data->all_cub);
}

/*
 ** Remplaces spaces by 1 in the map since it's up to
 ** us to handle the spaces as we like.
 */
void	remp_space_by_1(t_mlx *data)
{
	int	error;
	int	totlen;

	error = 0;
	totlen = ft_strlen(data->all_cub);
	data->tmp_start_map = data->start_map;
	while (data->all_cub[totlen] != ' ' && data->all_cub[totlen] != '1')
		totlen--;
	while (data->all_cub[totlen] == '1')
		totlen--;
	while (data->all_cub[totlen] == ' ')
		totlen--;
	if (data->all_cub[totlen] == '\n' && (data->all_cub[totlen - 1] != '1'))
		error = 1;
	if (error == 1)
		ft_error(data, "Error, incorrect bottom line");
	while (data->all_cub[data->start_map])
	{
		if (data->all_cub[data->start_map] == ' ')
			data->all_cub[data->start_map] = '1';
		data->start_map++;
	}
}

/*
 ** Launch fct to put the map in a seperated str, remplace spaces
 ** by 1, check if a map is def and def in last.
 */
void	malloc_strmap_remp_1(t_mlx *data)
{
	int	is_c;
	int	is_f;
	int	malloc_map;

	init_malloc_strmap_remp_1(data, &malloc_map, &is_c, &is_f);
	while (data->all_cub[data->i] == ' ' || data->all_cub[data->i] == '\n')
		data->i++;
	while (data->all_cub[data->i])
	{
		count_i(data, &data->ino, "NO");
		count_i(data, &data->iwe, "WE");
		count_i(data, &data->iea, "EA");
		count_i(data, &data->iso, "SO");
		count_i(data, &is_c, "C");
		count_i(data, &is_f, "F");
		if (data->ino == 1 && data->iso == 1 && data->iea == 1 \
				&& data->iwe == 1 && is_c == 1 && is_f == 1 \
				&& data->start_map == 0)
			data->start_map = data->i;
		data->i++;
	}
	remp_space_by_1(data);
	calc_malloc_fill1(data, &malloc_map);
	assign_map_fill1(data, malloc_map);
}
