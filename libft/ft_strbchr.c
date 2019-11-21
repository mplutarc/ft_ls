/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:07:30 by emaveric          #+#    #+#             */
/*   Updated: 2019/11/21 17:07:30 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strbchr(const char *s, int c)
{
	int		i;
	char 	*new;

	i = ft_strlen(s) - 1;
	new = ft_strdup(s);
	while (new[i + 1] != (char)c)
	{
		new[i] = '\0';
		if (!new[--i])
			return ((char *)new);
	}
	return (new);
}
