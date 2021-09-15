/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_in_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:25:04 by amontaut          #+#    #+#             */
/*   Updated: 2021/09/06 12:44:19 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 ** We need to put whats in the .cub im a str. To do so, first we 
 ** calculate what has to be malloced. 
 ** If the arg doesn't end by .cub or if the file doesn't exist,
 ** an error occurs. 
 */
void	malloc_allcub(t_mlx *data, int len_arg, char **argv, int *count)
{
	data->fd = 0;
	if (argv[1][len_arg - 4] == '.' && argv[1][len_arg - 3] == 'c' \
			&& argv[1][len_arg - 2] == 'u' && argv[1][len_arg - 1] == 'b')
	{
		data->fd = open(argv[1], O_RDONLY);
		if (data->fd == -1)
			ft_error(data, "Error, cannot read the file \
			 (file doesn't exist for ex)");
		data->ret = 1;
		while (data->ret > 0)
		{
			data->ret = get_next_line(data->fd, &data->buff, data);
			(*count) = (*count) + ft_strlen(data->buff);
			++data->line;
			(*count)++;
			ft_memdel((void *)&data->buff);
		}
		data->ret = get_next_line(data->fd, &data->buff, data);
		++data->line;
		(*count) = (*count) + ft_strlen(data->buff);
		ft_memdel((void *)&data->buff);
	}
	else
		ft_error(data, "Error, map doesn't end by .cub");
}

/*
 ** After the malloc is done, we put the content of the .cub in
 ** the dedicated string. (part 1/2)
 */
void	assign_allcub_1(t_mlx *data, char **argv, int count, int *k)
{
	data->all_cub = (char *)malloc((sizeof(char)) * (count + 2));
	if (data->all_cub == NULL)
		ft_error(data, "Malloc all_cub failed");
	data->fd = 0;
	data->ret = 0;
	data->line = 0;
	data->fd = open(argv[1], O_RDONLY);
	data->ret = 1;
	while (data->ret > 0)
	{
		data->ret = get_next_line(data->fd, &data->buff, data);
		data->line = 0;
		while (data->buff[data->line])
		{
			data->all_cub[(*k)] = data->buff[data->line];
			(*k)++;
			data->line++;
		}
		data->all_cub[(*k)] = '\n';
		(*k)++;
		ft_memdel((void *)&data->buff);
	}
}

/*
 ** After the malloc is done, we put the content of the .cub in
 ** the dedicated string. (part 2/2)
 */
void	assign_allcub_2(t_mlx *data, int k)
{
	data->ret = get_next_line(data->fd, &data->buff, data);
	data->line = 0;
	while (data->buff[data->line])
	{
		data->all_cub[k] = data->buff[data->line];
		k++;
		data->line++;
	}
	data->all_cub[k] = '\n';
	k++;
	data->all_cub[k] = '\0';
	ft_memdel((void *)&data->buff);
}

/*
 ** Through different fct, this one will :
 ** check the right nb of arg (2)
 ** check that the arg finishes by cub
 ** check that the file exists
 ** calc what has to be malloced
 ** assign the char all_cub which contains all the .cub
 */
void	check_nb_arg_gnl(t_mlx *data, int argc, char **argv)
{
	int	count;
	int	k;
	int	len_arg;

	count = 0;
	k = 0;
	if (argc == 2)
	{
		len_arg = ft_strlen(argv[1]);
		malloc_allcub(data, len_arg, argv, &count);
		if (count != 0)
		{
			assign_allcub_1(data, argv, count, &k);
			assign_allcub_2(data, k);
		}
	}
	else
	{
		data->fd = 0;
		data->ret = -1;
		ft_error(data, "Error, no map to read/no arg or too many args");
	}
	close(data->fd);
}
