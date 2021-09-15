/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:35:04 by amontaut          #+#    #+#             */
/*   Updated: 2021/08/03 19:42:22 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	neg = 1;
	i = 0;
	res = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * neg);
}

void	ft_memdel(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	int			i;

	i = 0;
	dest = dst;
	source = src;
	if (src == 0 && dst == 0)
		return (NULL);
	if (source < dest)
		while (len--)
			dest[len] = source[len];
	else
		while (len--)
			dest[i++] = *source++;
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned long	i;

	if (s == NULL)
		return (NULL);
	res = (char *)malloc((sizeof(char)) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
	{
		res[0] = '\0';
		return (res);
	}
	else
	{
		while (i < len)
		{
			res[i] = s[start + i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
}
