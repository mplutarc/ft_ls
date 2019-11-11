/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:11:32 by emaveric          #+#    #+#             */
/*   Updated: 2019/11/11 21:37:02 by emaveric         ###   ########.fr       */
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
		if ((opendir(tree->field) || fopen(tree->field, "rt"))) {
			if (ls->flag == 2 && ls->big_r == 0)//(!opendir(tree->field) && fopen(tree->field, "rt"))
			{
				tree->field = ft_strcut(tree->field, '/');
				ft_putendl(tree->field);
			}
			else if (!opendir(tree->field) && fopen(tree->field, "rt"))
				ft_putendl(tree->field);
			else
				directory(tree->field, ls);
		}
	/*	else if (fopen(tree->field, "r"))
			ft_putendl(tree->field);*/
		print(tree->right, ls); //Рекурсивная функция вывода правого поддерева
	}
}

void 	print_without_err(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{
		print_without_err(tree->left, ls);  //Рекурсивная функция вывода левого поддерева
		if ((ft_strcmp(tree->field, ".") != 0) || (ft_strcmp(tree->field, "..") != 0))
			ft_putendl(tree->field);
		else if (opendir(tree->field))//if (ls->big_r == 1)
			directory(tree->field, ls);
		print_without_err(tree->right, ls); //Рекурсивная функция вывода правого поддерева
	}
}

int 	output(t_ls *ls, struct s_node *tree)
{
	e_print(tree, ls);
	print(tree, ls);
	ls->flag = 0;
	return (0);
}