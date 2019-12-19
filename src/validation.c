/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:54:51 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/19 14:34:29 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// проверка на ''
// проверка на --
// проверка с флагами

int		valid_error(int ac, char **av)
{
	int		i;
	int			j;

	i = 1;
	j = 1;
	while (ac > 1  && i < ac && av[i][0] == '-')
	{
		while (av[i][j] != '\0')
		{
			if (av[i][j] >= 121 || av[i][j] < 65 || av[i][j] == 'E' ||
					av[i][j] == 'D' || (av[i][j] <= 75 && av[i][j] >= 73)
					|| av[i][j] == 'M' || av[i][j] == 'N' || av[i][j] == 'Q'
					|| av[i][j] == 'V' || (av[i][j] >= 88 && av[i][j] <= 96)
					|| av[i][j] == '!' || (av[i][j] >= 35 && av[i][j] <= 37)
					|| (av[i][j] >= 40 && av[i][j] <= 44) || (av[i][j] >= 46
					&& av[i][j] <= 62) || av[i][j] == '@' || (av[i][j] == '-'
					&& j >= 2))
			{
				ft_putstr("ls: illegal option -- ");
				ft_putchar(av[i][j]);
				ft_putchar('\n');
				ft_putendl("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]");
				return (ERROR);
			}
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}

int 	flag_ind(int ac, char **av, t_ls *ls)
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
			break;
		i++;
	}
	return (0);
}

int 	flag_sum(int ac, char **av, t_ls *ls)
{
	int 	i;
	int 	f_sum;

	i = 1;
	f_sum = 0;
	while (i < ac)
	{
		if ((i < ls->dh_index || ls->dh_index == 0) && (av[i][0] == '-' && ft_strcmp(av[i], "-") != 0))
			f_sum++;
		else
			break;
		i++;
	}
	if (!(ls->f_index = (int *)malloc(sizeof(int) * (f_sum + 1))))
		return (ERROR);
	flag_ind(ac, av, ls);
	return (0);
}

int 	dhyp_check(int ac, char **av, t_ls *ls)
{
	int 	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] != '-' || ft_strcmp(av[i], "-") == 0)
			break;
		if (av[i][0] == '-' && av[i][1] == '-')
		{
			if (av[i][2] != '\0')
				return (ERROR);
			else
			{
				ls->dh_index = i; // запоминаем с какого индекса --
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
		return (ERROR); //посмотреть ошибку ориг лс если ввести 3 --- и тп
	if (flag_sum(ac, av, ls) == ERROR)
		return (ERROR);
    return (0);
}
