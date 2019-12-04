/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:34:09 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/04 17:30:51 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strname(char *s, int c)
{
	int		i;
	char 	*new;
	char 	*tmp;

	i = ft_strlen(s);
	if (!(new = ft_strdup(s)))
		return (NULL);
	//free(s);
	while (new[i] != (char)c)
	{
		if (!new[--i])
			return ((char *)new);
	}
	tmp = &new[i + 1];
	free(new);
	return (tmp);
}
