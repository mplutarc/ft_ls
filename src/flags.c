/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:50:58 by mplutarc          #+#    #+#             */
/*   Updated: 2019/10/24 20:17:16 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int 	flag_valid(int ac, char **av, t_ls *ls)
{
	int 	i;
	int 	f_sum;

	i = 1;
	f_sum = 0;
	while (i < ac)
	{
		if ((!opendir(av[i]) || !fopen(av[i], "rt")) && ft_strcmp(av[i], "-") != 0)
			f_sum++;
		else
			break;
		i++;
	}
	if (!(ls->f_index = (int *)malloc(sizeof(int) * f_sum)))
		return (ERROR);
	i = 1;
	while (i < ac)
	{
		if ((!opendir(av[i]) || !fopen(av[i], "rt")) && ft_strcmp(av[i], "-") != 0)
			ls->f_index[i] = i;
		else
			break;
		i++;
	}
	return (0);
}

int 	flags(int ac, char **av, t_ls *ls)
{
	if (flag_valid(ac, av, ls) == ERROR)
		return (ERROR);
	return (0);
}