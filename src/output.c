/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:11:32 by emaveric          #+#    #+#             */
/*   Updated: 2019/11/07 22:44:19 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			e_print(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		e_print(tree->left, ls);  //Рекурсивная функция вывода левого поддерева
		if (!opendir(tree->field) && !fopen(tree->field, "rt"))
			directory(tree->field, ls);
		e_print(tree->right, ls); //Рекурсивная функция вывода правого поддерева
	}
}

void			print(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		print(tree->left, ls);  //Рекурсивная функция вывода левого поддерева
		if (opendir(tree->field) || fopen(tree->field, "rt"))
		{
			if (ls->flag == 2)
				ft_putendl(tree->field);
			else //if (ls->big_r == 1)
				directory(tree->field, ls);
		}
		print(tree->right, ls); //Рекурсивная функция вывода правого поддерева
	}
}

int 	output(t_ls *ls, struct s_node *tree)
{
	e_print(tree, ls);
	print(tree, ls);
	ls->flag = 0;
	return (0);
}