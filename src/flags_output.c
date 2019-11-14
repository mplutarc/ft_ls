/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:25:24 by emaveric          #+#    #+#             */
/*   Updated: 2019/11/14 19:22:21 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


void	big_r_flag_print(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		big_r_flag_print(tree->left, ls);  //Рекурсивная функция вывода левого поддерева
		if ((opendir(tree->field) || fopen(tree->field, "rt"))) {
		/*	if (!opendir(tree->field) && fopen(tree->field, "rt"))
			{
				tree->field = ft_strcut(tree->field, '/');
				if (tree->field[0] != '.')
				{
					ft_putstr(tree->field);
					ft_putchar('\t');
				}
			}*/
			if (opendir(tree->field) && fopen(tree->field, "rt"))
				if (ft_strcmp(ft_strcut(tree->field, '/'), ".") != 0 &&
						ft_strcmp(ft_strcut(tree->field, '/'), "..") != 0)
					directory(tree->field, ls);
		}
		big_r_flag_print(tree->right, ls); //Рекурсивная функция вывода правого поддерева
	}
}

/*
void	r_flag_print(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		r_flag_print(tree->right, ls);  //Рекурсивная функция вывода левого поддерева
		if ((opendir(tree->field) || fopen(tree->field, "rt")))
		{
			if (ls->r == 1 && ls->flag == 2)//(!opendir(tree->field) && fopen(tree->field, "rt"))
			{
				tree->field = ft_strcut(tree->field, '/');
				if (tree->field[0] != '.')
				{
					ft_putstr(tree->field);
					ft_putchar('\t');
				}
				//ft_putendl(tree->field);
			}
				*/
/*		else if (!opendir(tree->field) && fopen(tree->field, "rt"))
							ft_putendl(tree->field);*//*

			else
				directory(tree->field, ls);
		}
		r_flag_print(tree->left, ls); //Рекурсивная функция вывода правого поддерева
	}
}*/
