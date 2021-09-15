/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:27:05 by amontaut          #+#    #+#             */
/*   Updated: 2021/09/06 12:57:20 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdarg.h>
# include <stdint.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_texture
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;

}	t_texture;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	int			rx;
	int			ry;
	int			real_rx;
	int			real_ry;
	double		x;
	double		y;
	int			hit;
	double		perpwalldist;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			side;
	int			stepx;
	int			stepy;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		movespeed;
	double		rotspeed;
	double		olddirx;
	double		oldplanex;
	int			texdir;
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
	int			up;
	int			down;
	int			left;
	int			right;
	int			camright;
	int			camleft;
	char		*path_no;
	char		*path_so;
	char		*path_ea;
	char		*path_we;
	int			final_c;
	int			final_f;
	char		*all_cub;
	int			check_1_no;
	int			check_1_so;
	int			check_1_ea;
	int			check_1_we;
	int			check_1_c;
	int			check_1_f;
	char		*str_map;
	char		*map_add_1;
	int			final_lenght;
	int			final_height;
	int			i;
	int			malloc_no;
	int			malloc_so;
	int			malloc_ea;
	int			malloc_we;
	int			malloc_c;
	int			malloc_f;
	int			r_c;
	int			g_c;
	int			b_c;
	int			r_f;
	int			g_f;
	int			b_f;
	int			fd;
	int			ret;
	char		*buff;
	char		buf[BUFFER_SIZE + 1];
	int			line;
	int			ino;
	int			iso;
	int			iwe;
	int			iea;
	int			start_map;
	int			tmp_start_map;
	int			count_char;
	char		**worldmap;
	t_texture	text[4];
}	t_mlx;

int		ft_atoi(const char	*str);
void	ft_memdel(void	**ptr);
size_t	ft_strlen(const char	*s);
void	*ft_memmove(void	*dst, const void	*src, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		copy_first_line(char	**xtra, char	*buf);
int		copy_line(char **line, int i, char *xtra, int ret);
int		define_i(char	**xtra);
int		empty_xtra(char **xtra, char **line, int ret, t_mlx *data);
int		get_next_line(int fd, char **line, t_mlx *data);
char	*ft_itoa(int n);
void	last_frees(t_mlx *data);
int		ft_error(t_mlx *data, char *msg);
int		kill_all(t_mlx *data);
int		exit_wrong_path(t_mlx *data);
int		ft_exitx(t_mlx *data);
void	boucle_raycast(t_mlx *data, int tmpstart);
void	init_raycast_1(t_mlx *data);
void	init_main_1(t_mlx *data);
void	init_main_2(t_mlx *data);
void	init_main_3(t_mlx *data);
void	init_mlx(t_mlx *data);
void	init_raycast_2(t_mlx *data);
void	init_raycast_1(t_mlx *data);
void	init_malloc_strmap_remp_1(t_mlx *data, int *malloc_map, int *is_c, \
		int *is_f);
void	init_pos_1(t_mlx *data, int *check_ligne, double x, double y);
void	init_pos_2(t_mlx *data, int *check_ligne, double x, double y);
void	check_path_cf_1(t_mlx *data, int *count_malloc);
void	check_path_cf_2(t_mlx *data, int *count_malloc);
void	check_path_cf_3(t_mlx *data, int *count_malloc);
void	check_int_cf(t_mlx *data, int R, int G, int B);
void	up_down(t_mlx *data);
void	right_left(t_mlx *data);
void	cam_right(t_mlx *data);
void	cam_left(t_mlx *data);
void	fill_char_text_cf(t_mlx *data);
void	check_treat_rgb_c(t_mlx *data);
void	check_treat_rgb_f(t_mlx *data);
void	fill_path_text(t_mlx *data, int *j, char *name, char **path);
void	fill_path_c(t_mlx *data, int *R, int *G, int *B);
void	fill_path_f(t_mlx *data, int *R, int *G, int *B);
void	malloc_strmap_remp_1(t_mlx *data);
void	check_nb_arg_gnl(t_mlx *data, int argc, char **argv);
void	fill_map_1(t_mlx *data);
void	assign_map_double_char(t_mlx *data);
int		ft_keypress(int keycode, t_mlx *data);
int		ft_keyrelease(int keycode, t_mlx *data);
int		raycast(t_mlx *data);
void	deter_posxy(t_mlx *data);
void	deter_malloc_text_cf(t_mlx *data);
void	check_walls_are_1(t_mlx *data);
void	error_gnl(t_mlx *data);
void	destroy_img(t_mlx *data);

#endif
