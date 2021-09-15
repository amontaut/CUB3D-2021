/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 22:02:45 by amontaut          #+#    #+#             */
/*   Updated: 2021/08/26 19:34:12 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	empty_xtra_2(char **xtra, int *i, char **line)
{
	while ((*xtra)[(*i)] && (*xtra)[(*i)] != '\n' && (*xtra)[(*i)] != '\0')
		(*i)++;
	if ((*xtra)[(*i)] == '\n')
		return (copy_line(line, (*i), *xtra, 1));
	else if ((copy_line(line, (*i), *xtra, 0)) || (*xtra)[(*i)] == '\0')
	{
		ft_memdel((void *)&*xtra);
		*xtra = NULL;
		return (0);
	}
	return (0);
}

int	empty_xtra(char **xtra, char **line, int ret, t_mlx *data)
{
	int	i;

	i = 0;
	if ((*xtra) != NULL)
	{
		data->buf[ret] = '\0';
		*xtra = ft_strjoin(*xtra, data->buf);
		empty_xtra_2(xtra, &i, line);
	}
	else if (*(xtra) == NULL)
	{
		*line = malloc(sizeof(char *) * 1);
		if (*line == NULL)
			error_gnl(data);
		(*line)[0] = '\0';
	}
	return (0);
}

void	gnl_2(char **xtra, int *i, char **line, int *ret)
{
	if ((*xtra))
		(*i) = define_i(xtra);
	*line = NULL;
	*ret = 1;
}

int	get_next_line(int fd, char **line, t_mlx *data)
{
	static char	*xtra;
	int			ret;
	int			i;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, data->buf, 0) < 0)
		error_gnl(data);
	gnl_2(&xtra, &i, line, &ret);
	if (xtra && xtra[i] == '\n')
		return (copy_line(line, i, xtra, 1));
	while (ret > 0)
	{
		ret = read(fd, data->buf, BUFFER_SIZE);
		data->buf[ret] = '\0';
		if (xtra == NULL && fd != STDIN_FILENO)
			copy_first_line(&xtra, data->buf);
		else
		{
			xtra = ft_strjoin(xtra, data->buf);
			i = define_i(&xtra);
			if (xtra && xtra[i] == '\n')
				return (copy_line(line, i, xtra, 1));
		}
	}
	return (empty_xtra(&xtra, line, ret, data));
}
