/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:52:33 by mplutarc          #+#    #+#             */
/*   Updated: 2019/11/29 16:14:07 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *str;
	char *res;

	str = (char *)s;
	res = NULL;
	while (*str)
	{
		if (*str == c)
			res = str;
		str++;
	}
	if (c == '\0')
		return (str);
	return (res);
}
