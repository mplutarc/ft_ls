/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:43:38 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/12 19:36:38 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncut(char *s, int start, int end)
{
	int		i;
	char	*new;

	i = end;
	while (s[i] != '\0')
	{
		s[i] = '\0';
		i++;
	}
	int j = 0;
	while (j < start)
	{
		free(&s[j]);
		j++;
	}
	return (&s[start]);
}
