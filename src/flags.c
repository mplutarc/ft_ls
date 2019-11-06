/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:50:58 by mplutarc          #+#    #+#             */
/*   Updated: 2019/11/06 15:34:30 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// t_ls	find_flag()
// {
	
// }

void			print(struct s_node *tree)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		print(tree->left);  //Рекурсивная функция вывода левого поддерева
		//if (!opendir(tree->field) || !fopen(tree->field, "rt"))
			directory(tree->field);
		print(tree->right); //Рекурсивная функция вывода правого поддерева
	}
}

int 	flag_valid(int ac, char **av, t_ls *ls)
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
	i = 1;
	while (i < ac)
	{
		if ((i < ls->dh_index || ls->dh_index == 0) && (av[i][0] == '-' && ft_strcmp(av[i], "-") != 0))
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