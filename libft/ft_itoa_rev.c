/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_rev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:56:53 by mplutarc          #+#    #+#             */
/*   Updated: 2019/12/19 15:27:32 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_ft_strnew(int size)
{
	char	*res;
	int		i;

	if (size + 1 < 0)
		return (NULL);
	if (!(res = (char *)ft_memalloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		res[i] = ' ';
		i++;
	}
	return (res);
}

char			*ft_itoa_rev(int n, int size)
{
	char	*res;
	int		i;
	int		j;

	j = size;
	if (!(res = ft_ft_strnew(sizeof(char) * (size + 1))))
		return (NULL);
	res[size] = ' ';
	size--;
	while (size)
	{
		res[size] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	i = 1;
	while (res[i] == '0')
	{
		res[i] = ' ';
		i++;
	}
	res[j + 1] = '\0';
	if (res[j - 1] == ' ')
		res[j - 1] = '0';
	return (res);
}
