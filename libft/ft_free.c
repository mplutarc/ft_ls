/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:09:43 by mplutarc          #+#    #+#             */
/*   Updated: 2019/11/29 16:14:07 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **res, size_t j)
{
	while (j)
		free(res[--j]);
	free(res);
	res = NULL;
	return (NULL);
}
