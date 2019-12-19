/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:33:01 by mplutarc          #+#    #+#             */
/*   Updated: 2019/12/19 14:34:40 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mal;

	mal = (void*)malloc(sizeof(void) * size);
	if (mal)
	{
		ft_bzero(mal, size);
		return (mal);
	}
	return (NULL);
}
