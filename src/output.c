/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:11:32 by emaveric          #+#    #+#             */
/*   Updated: 2019/11/14 20:18:19 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	e_print(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		e_print(tree->left, ls);  //Рекурсивная функция вывода левого поддерева
		if (!opendir(tree->field) && !fopen(tree->field, "rt"))
			directory(tree->field, ls);
		e_print(tree->right, ls); //Рекурсивная функция вывода правого поддерева
	}
}

void	print(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		print(tree->left, ls);  //Рекурсивная функция вывода левого поддерева
		if ((opendir(tree->field) || fopen(tree->field, "rt")))
		{
			if ((ls->flag == 2 && (ls->f_sum == 0 || ls->r == 1))) /*||
				(!opendir(tree->field) && fopen(tree->field, "rt")))*/ //&& ls->big_r == 0)//(!opendir(tree->field) && fopen(tree->field, "rt"))
			{
				tree->field = ft_strcut(tree->field, '/');
				if (tree->field[0] != '.')
				{
					ft_putstr(tree->field);
					ft_putchar('\t');
				}
				//ft_putendl(tree->field);
			}
/*			else if (!opendir(tree->field) && fopen(tree->field, "rt"))
				ft_putendl(tree->field);*/
			else /*if (ft_strcmp(ft_strcut(tree->field, '/'), ".") != 0 &&
					ft_strcmp(ft_strcut(tree->field, '/'), "..") != 0)*/
				directory(tree->field, ls);
		}
		print(tree->right, ls); //Рекурсивная функция вывода правого поддерева
	}
}

int 	output(t_ls *ls, struct s_node *tree)
{
	e_print(tree, ls);
	/*if (ls->r == 1)
		r_flag_print(tree, ls);*/
	print(tree, ls);
	/*if (ls->big_r == 1)
	{
		ft_putchar('\n');
		ft_putendl(tree->field);
		big_r_flag_print(tree, ls);
	}*/
	ls->flag = 0;
	return (0);
}