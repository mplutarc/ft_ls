/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:11:32 by emaveric          #+#    #+#             */
/*   Updated: 2019/11/20 18:48:24 by emaveric         ###   ########.fr       */
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
			if (ls->flag == 2) //&& (ls->f_sum == 0 || ls->r == 1))) /*||
				//(!opendir(tree->field) && fopen(tree->field, "rt"))) //&& ls->big_r == 0)//(!opendir(tree->field) && fopen(tree->field, "rt"))
			{
				//tree->field = ft_strcut(tree->field, '/');
				if (ft_strname(tree->field, '/')[0] != '.')
				{
					ft_putstr(ft_strname(tree->field, '/'));
					ft_putchar('\t');
				/*	if (ls->big_r == 1)
						ft_putchar('\n');*/
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
		if (ft_strcmp(ft_strname(tree->field, '/'), ".") == 0 && ls->big_r == 1
			&& ls->ind != 1)
			ft_putchar('\n');
	}
}

int 	output(t_ls *ls, struct s_node *tree)
{
	e_print(tree, ls);
	/*if (ls->r == 1)
		r_flag_print(tree, ls);*/
	if (ls->i == 0 && ls->big_r == 0 && ls->a == 0 && ls->l == 0)
		print(tree, ls);
	else if (ls->i == 1)
		i_flag_print(tree, ls);
	else if (ls->a == 1)
		a_flag_print(tree, ls);
	if (ls->big_r == 1)
	{
		//ls->flag = 2;
		if (ls->flag == 0)
		{
			//last_dir_check(tree, ls);
			print(tree, ls);
			//ft_putchar('\n');
		}
		else if (ls->flag == 2)
		{
			//last_dir_check(tree, ls);
			print(tree, ls);
			ft_putchar('\n');
			big_r_flag_print(tree, ls);
		}
		//ft_putchar('\n');
		//ft_putendl(tree->field);
		//big_r_flag_print(tree, ls);
		//ft_putchar('\n');
	}
	else if (ls->l == 1)
	{
		ft_putstr("total");
		ft_putchar(' ');
		ft_putnbr(ls->blocks);
		ft_putchar('\n');
		l_flag_print(tree, ls);
	}
	ls->flag = 0;
	return (0);
}