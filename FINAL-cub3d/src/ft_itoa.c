/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:32:37 by amontaut          #+#    #+#             */
/*   Updated: 2021/08/03 19:42:11 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	size_response(int n)
{
	int	size_res;
	int	div;

	div = n;
	size_res = 0;
	while (div != 0)
	{
		div = div / 10;
		size_res++;
	}
	return (size_res);
}

static char	*n_is_pos(int n, int size_res)
{
	char	*res;
	int		j;

	res = (char *)malloc(sizeof(char) * size_res + 1);
	if (res == NULL)
		return (NULL);
	j = size_res - 1;
	while (n != 0)
	{
		while (j >= 0)
		{
			res[j] = n % 10 + '0';
			n = n / 10;
			j--;
		}
	}
	res[size_res] = '\0';
	return (res);
}

static char	*n_is_neg(int n, int size_res)
{
	char	*res;
	int		j;

	res = (char *)malloc(sizeof(char) * (size_res + 2));
	if (res == NULL)
		return (NULL);
	j = size_res;
	res[0] = '-';
	while (n != 0)
	{
		while (j > 0)
		{
			res[j] = n % 10 + '0';
			n = n / 10;
			j--;
		}
	}
	res[size_res + 1] = '\0';
	return (res);
}

static char	*n_is_zero(int size_res)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (size_res + 2));
	if (res == NULL)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n > 0)
		return (n_is_pos(n, size_response(n)));
	else if (n < 0)
	{
		n = n * -1;
		return (n_is_neg(n, size_response(n)));
	}
	else
		return (n_is_zero(size_response(n)));
	return (NULL);
}
