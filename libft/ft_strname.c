/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:34:09 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/05 20:48:45 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strname(char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (s[i] != (char)c)
	{
		if (!s[--i])
			return ((char *)s);
	}
	return ((char *)&s[i + 1]);
}
