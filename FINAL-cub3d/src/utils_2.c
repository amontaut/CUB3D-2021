/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:42:01 by amontaut          #+#    #+#             */
/*   Updated: 2021/08/03 19:42:28 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		l;
	int		i;

	l = 0;
	while (s1[l])
		l++;
	copy = (char *)malloc((l + 1) * sizeof(char));
	if (copy == NULL)
		return (0);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*res;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < len1)
		res[i] = s1[i];
	ft_memdel((void *)&s1);
	s1 = NULL;
	i = -1;
	while (++i < len2)
		res[i + len1] = s2[i];
	res[i + len1] = '\0';
	return (res);
}

int	copy_line(char **line, int i, char *xtra, int ret)
{
	int	len;

	*line = ft_substr(xtra, 0, i);
	i = i + ret;
	len = ft_strlen(xtra + i) + 1;
	ft_memmove(xtra, xtra + i, len);
	return (ret);
}

int	define_i(char **xtra)
{
	int	i;

	i = 0;
	while ((*xtra)[i] && (*xtra)[i] != '\n' && (*xtra)[i] != '\0')
		i++;
	return (i);
}

int	copy_first_line(char **xtra, char *buf)
{
	int	i;

	i = 0;
	*xtra = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if ((*xtra) == NULL)
		return (-1);
	while (i < BUFFER_SIZE)
	{
		(*xtra)[i] = buf[i];
		i++;
	}
	(*xtra)[i] = '\0';
	return (1);
}
