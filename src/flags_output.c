/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:25:24 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/12 20:51:40 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	last_dir_check(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		last_dir_check(tree->left, ls);  //Рекурсивная функция вывода левого поддерева
		if (tree->mode[0] == 'd')
		{
			ls->ind = 1;
			return;
		}
		last_dir_check(tree->right, ls); //Рекурсивная функция вывода правого поддерева
	}
}

void	big_r_flag_print(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		big_r_flag_print(tree->left, ls);  //Рекурсивная функция вывода левого поддерева
		if (tree->mode[0] == 'd')
		{
			if (ls->ind == 3 && tree->flag != 1)
			/*	if (ft_strcmp(ft_strname(tree->field, '/'), ".") != 0 &&
					ft_strcmp(ft_strname(tree->field, '/'), "..") != 0)*/
				{
					ft_putchar('\n');
					last_dir_check(tree, ls);
				}
			if (ls->ind == 1 && tree->flag != 1)
				{
					ft_putchar('\n');
					//ls->ind = 3;
				}
		/*	if (ft_strcmp(ft_strname(tree->field, '/'), ".") != 0 &&
				ft_strcmp(ft_strname(tree->field, '/'), "..") != 0 &&
					(ft_strname(tree->field, '/')[0] != '.' || ls->a == 1)
					&& tree->mode[0] != 'l')*/
		if ((ft_strname(tree->field, '/')[0] != '.' || ls->a == 1) &&
			tree->mode[0] != 'l' && tree->flag != 1)
			{
				ft_putstr(tree->field);
				ft_putstr(":\n");
				directory(tree->field, ls);
				ls->ind = 1;
			}
		}
		big_r_flag_print(tree->right, ls); //Рекурсивная функция вывода правого поддерева
	}
}

void    l_flag_print(struct s_node *tree, t_ls *ls)
{
	if (ls->flag == 2 || (ls->flag == 0 && files(tree, ".") == 0))
		if (ft_strname(tree->field, '/')[0] != '.' || ls->a == 1)
		{
			ft_putendl(into_string(tree, ls));
			// ft_putstr(tree->mode);
			// ft_putchar(' ');
			// ft_putnbr(tree->links);
			// ft_putchar(' ');
			// ft_putstr(tree->uid);
			// ft_putchar(' ');
			// ft_putstr(tree->gid);
			// ft_putchar(' ');
			// ft_putnbr(tree->size);
			// ft_putchar(' ');
			// tree->time = ft_strncut(tree->time, 4, 16);
			// ft_putstr(tree->time);
			// ft_putchar(' ');
			ft_putendl(ft_strname(tree->field, '/'));
			ft_putchar('\n');
		}
}

/*void    a_flag_print(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		a_flag_print(tree->left, ls);  //Рекурсивная функция вывода левого поддерева
		if (ls->flag == 2 || (ls->flag == 0 && files(tree, ".") == 0))
		{
			tree->field = ft_strcut(tree->field, '/');
			ft_putstr(tree->field);
			ft_putchar('\t');
		}
*//*			else if (!opendir(tree->field) && fopen(tree->field, "rt"))
				ft_putendl(tree->field);*//*
		else if (opendir(tree->field))
			directory(tree->field, ls);
		a_flag_print(tree->right, ls); //Рекурсивная функция вывода правого поддерева
	}
}*/

void    i_flag_print(struct s_node *tree, t_ls *ls)
{
	if (ls->flag == 2 || (ls->flag == 0 && files(tree, ".") == 0))
		if (ft_strname(tree->field, '/')[0] != '.' || ls->a == 1)
		{
			ft_putnbr(tree->ino);
			ft_putchar(' ');
		}
}