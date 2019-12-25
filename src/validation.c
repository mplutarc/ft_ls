/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:54:51 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/25 13:56:44 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		flag_ind(int ac, char **av, t_ls *ls)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if ((i < ls->dh_index || ls->dh_index == 0) &&
			(av[i][0] == '-' && ft_strcmp(av[i], "-") != 0))
		{
			ls->f_index[i] = i;
			find_flag(ls, av, i);
			ls->f_sum++;
		}
		else
			break ;
		i++;
	}
	return (0);
}

int		flag_sum(int ac, char **av, t_ls *ls)
{
	int		i;
	int		f_sum;

	i = 1;
	f_sum = 0;
	while (i < ac)
	{
		if ((i < ls->dh_index ||
		ls->dh_index == 0) && (av[i][0] == '-' && ft_strcmp(av[i], "-") != 0))
			f_sum++;
		else
			break ;
		i++;
	}
	if (!(ls->f_index = (int *)malloc(sizeof(int) * (f_sum + 1))))
		return (ERROR);
	flag_ind(ac, av, ls);
	return (0);
}

int		dhyp_check(int ac, char **av, t_ls *ls)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] != '-' || ft_strcmp(av[i], "-") == 0)
			break ;
		if (av[i][0] == '-' && av[i][1] == '-')
		{
			if (av[i][2] != '\0')
				return (ERROR);
			else
			{
				ls->dh_index = i;
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int		validation(int ac, char **av, t_ls *ls)
{
	if (valid_error(ac, av) == ERROR)
		return (ERROR);
	if (dhyp_check(ac, av, ls) == ERROR)
		return (ERROR);
	if (flag_sum(ac, av, ls) == ERROR)
		return (ERROR);
	return (0);
}
