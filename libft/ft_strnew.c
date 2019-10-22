/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:51:47 by mplutarc          #+#    #+#             */
/*   Updated: 2019/10/21 20:29:07 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;

	if (size + 1 == 0)
		return (NULL);
	if (!(res = (char *)ft_memalloc(size + 1)))
		return (NULL);
	return (res);
}
