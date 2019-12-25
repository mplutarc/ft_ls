/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:50:58 by mplutarc          #+#    #+#             */
/*   Updated: 2019/12/25 13:56:44 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			find_flag(t_ls *ls, char **av, int i)
{
	if (ft_strchr(av[ls->f_index[i]], 'l'))
		ls->l = 1;
	if (ft_strchr(av[ls->f_index[i]], 'i'))
		ls->i = 1;
	if (ft_strchr(av[ls->f_index[i]], 'a'))
		ls->a = 1;
	if (ft_strchr(av[ls->f_index[i]], 'r'))
		ls->r = 1;
	if (ft_strchr(av[ls->f_index[i]], 't'))
		ls->t = 1;
	if (ft_strchr(av[ls->f_index[i]], 'R'))
		ls->big_r = 1;
}
