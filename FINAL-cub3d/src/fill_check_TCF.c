/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_check_TCF.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:00:13 by amontaut          #+#    #+#             */
/*   Updated: 2021/09/06 12:52:32 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 ** While loop which launch fct that fills the texture's, C and F
 ** path without spaces.
 */
void	while_fill_cf(t_mlx *data, int *print_error_map_not_last)
{
	while (data->all_cub[data->i] == ' ')
		data->i++;
	fill_path_text(data, &data->ino, "NO", &data->path_no);
	fill_path_text(data, &data->iso, "SO", &data->path_so);
	fill_path_text(data, &data->iea, "EA", &data->path_ea);
	fill_path_text(data, &data->iwe, "WE", &data->path_we);
	fill_path_c(data, &data->r_c, &data->g_c, &data->b_c);
	fill_path_f(data, &data->r_f, &data->g_f, &data->b_f);
	if (data->all_cub[data->i] != '1' && data->all_cub[data->i] != '0' && \
			data->all_cub[data->i] != '\n' && data->all_cub[data->i] != ' ' \
			&& data->all_cub[data->i] != 'E' && data->all_cub[data->i] != 'N' \
			&& data->all_cub[data->i] != 'W' && data->all_cub[data->i] != 'S')
		(*print_error_map_not_last) = 1;
	if (data->all_cub[data->i] == '1' && (data->check_1_f != 1 \
				|| data->check_1_c != 1 || data->check_1_we != 1 \
				|| data->check_1_no != 1 || data->check_1_so != 1 \
				|| data->check_1_ea != 1))
		(*print_error_map_not_last) = 1;
	data->i++;
}

/*
 ** Check if all text and C F are def, if the map is defined last
 ** and if there are no char that should not be here
 */
void	fill_char_text_cf(t_mlx *data)
{
	int	print_error_map_not_last;

	print_error_map_not_last = 0;
	data->i = 0;
	while (data->all_cub[data->i])
		while_fill_cf(data, &print_error_map_not_last);
	if (print_error_map_not_last == 1 && data->check_1_f == 1 \
			&& data->check_1_c == 1 && data->check_1_we == 1 \
			&& data->check_1_no == 1 && data->check_1_so == 1 \
			&& data->check_1_ea == 1)
		ft_error(data, "Error, map not in last or too many datas/chars");
	if (data->check_1_f != 1 || data->check_1_c != 1 \
			|| data->check_1_we != 1 || data->check_1_no != 1 \
			|| data->check_1_so != 1 || data->check_1_ea != 1)
		ft_error(data, "Error, a data is not defined (C, F, or text)");
}

/*
 ** Launch the fct that checks if the R G B are 0 =< RGB =< 255, 
 ** and puts the RGB value in a final char for the C.
 */
void	check_treat_rgb_c(t_mlx *data)
{
	char	*char_gc;
	char	*char_bc;

	check_int_cf(data, data->r_c, data->g_c, data->b_c);
	char_gc = NULL;
	char_bc = NULL;
	char_gc = ft_itoa(data->g_c);
	char_bc = ft_itoa(data->b_c);
	data->final_c = 0;
	data->final_c = data->final_c * 1 + data->r_c;
	if (ft_strlen(char_gc) == 1)
		data->final_c = data->final_c * 10 + data->g_c;
	if (ft_strlen(char_gc) == 2)
		data->final_c = data->final_c * 100 + data->g_c;
	if (ft_strlen(char_gc) == 3)
		data->final_c = data->final_c * 1000 + data->g_c;
	if (ft_strlen(char_bc) == 1)
		data->final_c = data->final_c * 10 + data->b_c;
	if (ft_strlen(char_bc) == 2)
		data->final_c = data->final_c * 100 + data->b_c;
	if (ft_strlen(char_bc) == 3)
		data->final_c = data->final_c * 1000 + data->b_c;
	printf("final int C %d\n", data->final_c);
	ft_memdel((void *)&char_gc);
	ft_memdel((void *)&char_bc);
}

/*
 ** Launch the fct that checks if the R G B are 0 =< RGB =< 255, 
 ** and puts the RGB value in a final char for the F.
 */
void	check_treat_rgb_f(t_mlx *data)
{
	char	*char_gf;
	char	*char_bf;

	char_gf = NULL;
	char_bf = NULL;
	check_int_cf(data, data->r_f, data->g_f, data->b_f);
	char_gf = ft_itoa(data->g_f);
	char_bf = ft_itoa(data->b_f);
	data->final_f = 0;
	data->final_f = data->final_f * 1 + data->r_f;
	if (ft_strlen(char_gf) == 1)
		data->final_f = data->final_f * 10 + data->g_f;
	if (ft_strlen(char_gf) == 2)
		data->final_f = data->final_f * 100 + data->g_f;
	if (ft_strlen(char_gf) == 3)
		data->final_f = data->final_f * 1000 + data->g_f;
	if (ft_strlen(char_bf) == 1)
		data->final_f = data->final_f * 10 + data->b_f;
	if (ft_strlen(char_bf) == 2)
		data->final_f = data->final_f * 100 + data->b_f;
	if (ft_strlen(char_bf) == 3)
		data->final_f = data->final_f * 1000 + data->b_f;
	printf("final int F %d\n", data->final_f);
	ft_memdel((void *)&char_gf);
	ft_memdel((void *)&char_bf);
}
