/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:34:09 by emaveric          #+#    #+#             */
/*   Updated: 2019/11/19 18:43:15 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strname(const char *s, int c)
{
	int		i;
	char 	*new;

	i = ft_strlen(s);
	new = ft_strdup(s);
	while (new[i] != (char)c)
	{
		if (!new[--i])
			return ((char *)new);
	}
	return ((char *)&new[i + 1]);
}
