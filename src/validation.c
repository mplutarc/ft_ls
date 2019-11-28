/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:54:51 by emaveric          #+#    #+#             */
/*   Updated: 2019/11/28 19:28:21 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


// проверка на ''
// проверка на --
// проверка с флагами

/*int 	cur_dir(char *theDir, t_ls *ls)
{
	DIR				*dir;
	struct dirent	*entry;
	int 			i;

	i = 0;
	dir = opendir(theDir);
	while ((entry = readdir(dir)))
		i++;
	if (!(ls->c_dir = (char **)malloc(sizeof(char *) * (i + 1))))
		return (ERROR);
	i = 1;
	dir = opendir(theDir);
	while ((entry = readdir(dir)))
	{
		ls->c_dir[i] = ft_strdup(entry->d_name);
		i++;
	}
	sorting(i, ls->c_dir, ls);
	return (0);
}*/

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
	if (!(ls->f_index = (int *)malloc(sizeof(int) * f_sum)))
		return (ERROR);
	flag_ind(ac, av, ls);
	return (0);
}

/*int 	dir_err_check(int ac, char **av, t_ls *ls)
{
	int 	i;

	i = 1;
	while (i < ac)
	{
		if (!opendir(av[i]) || !fopen(av[i], "rt"))
			if ((av[i][0] != '-') || ft_strcmp(av[i], "-") == 0)
			{
				ls->e_sum++;
				//directory(av[i]);
			}
		i++;
	}
	if (!(ls->e_index = (int *)malloc(sizeof(int) * ls->e_sum)))
		return (ERROR);
	return (0);
}*/

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

/*int 	hyp_check(int ac, char **av, t_ls *ls)
{
	int 	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] != '-' || (av[i][0] == '-' && av[i][1] == '\0')) // папка может быть названа -
			ls->flag = 1;
		else if ((!opendir(av[i]) || !fopen(av[i], "rt")) && av[i][0] == '-' && ls->flag == 1)
		{
			ls->e_sum++;
			//directory(av[i]);
		}
		i++;
	}
	return (0);
}*/

int		validation(int ac, char **av, t_ls *ls)
{
	if (dhyp_check(ac, av, ls) == ERROR)
		return (ERROR); //посмотреть ошибку ориг лс если ввести 3 --- и тп
	if (flag_sum(ac, av, ls) == ERROR)
		return (ERROR);
/*	int 	i;
	int 	j;

	j = 1;
	i = 1;
   hyp_check(ac, av ,ls);
   if (dir_err_check(ac, av, ls) == ERROR)
   		return (ERROR);
	ls->flag = 0;
	while (i < ac)
	{
		if (!opendir(av[i]) || !fopen(av[i], "rt"))
			if ((av[i][0] != '-') || ft_strcmp(av[i], "-") == 0)
			{
				ls->e_index[j] = i;
				j++;
			}
		if (av[i][0] != '-' || (av[i][0] == '-' && av[i][1] == '\0')) // папка может быть названа -
			ls->flag = 1;
		else if ((!opendir(av[i]) || !fopen(av[i], "rt")) && av[i][0] == '-' && ls->flag == 1)
		{
			ls->e_index[j] = i;
			j++;
		}
		i++;
	}*/
    return (0);
}