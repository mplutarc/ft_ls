/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:42:27 by mplutarc          #+#    #+#             */
/*   Updated: 2019/11/09 18:49:19 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_memalloc(sizeof(char)));
	len = ft_strlen(&s[i]);
	while ((&s[i])[len - 1] == ' ' || (&s[i])[len - 1] == '\n'
		|| (&s[i])[len - 1] == '\t')
		len--;
	res = ft_memalloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res = ft_strncpy(res, &s[i], len);
	return (res);
}
