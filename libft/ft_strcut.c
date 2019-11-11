/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:33:56 by emaveric          #+#    #+#             */
/*   Updated: 2019/11/11 20:33:56 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (!s[i++])
			return (NULL);
	}
	return ((char *)&s[i + 1]);
}
