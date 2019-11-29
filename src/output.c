/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:11:32 by emaveric          #+#    #+#             */
/*   Updated: 2019/11/29 21:19:25 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	e_print(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		e_print(tree->left, ls);  //Рекурсивная функция вывода левого поддерева
		if (files(tree, ".") == ERROR && !opendir(tree->field))
			directory(tree->field, ls);
		e_print(tree->right, ls); //Рекурсивная функция вывода правого поддерева
	}
}

void	print(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		print(tree->left, ls);  //Рекурсивная функция вывода левого поддерева
		if (ls->flag == 2 || (ls->flag == 0 && files(tree, ".") == 0))
		{
			//tree->field = ft_strcut(tree->field, '/');
			if (ft_strname(tree->field, '/')[0] != '.' || ls->a == 1) {
				if (ls->i == 1) {
					ft_putnbr(tree->ino);
					ft_putchar(' ');
				}
				if (ls->l == 1) {
					ft_putstr(tree->mode);
					ft_putchar(' ');
					ft_putnbr(tree->links);
					ft_putchar(' ');
					ft_putstr(tree->uid);
					ft_putchar(' ');
					ft_putstr(tree->gid);
					ft_putchar(' ');
					ft_putnbr(tree->size);
					ft_putchar(' ');
					tree->time = ft_strncut(tree->time, 4, 16);
					ft_putstr(tree->time);
					ft_putchar(' ');
					ft_putendl(ft_strname(tree->field, '/'));
				}
				else
				{
					ft_putstr(ft_strname(tree->field, '/'));
					ft_putchar('\t');
				}
			}
			//ft_putendl(tree->field);
		}
		else if (opendir(tree->field))// && tree->mode[0] != 'l')
			directory(tree->field, ls);
		//}
		print(tree->right, ls); //Рекурсивная функция вывода правого поддерева
		/*if (ft_strcmp(ft_strname(tree->field, '/'), ".") == 0 && ls->big_r == 1
			&& ls->ind != 1)
			ft_putchar('\n');*/
	}
}

int 	output(t_ls *ls, struct s_node *tree)
{
	if (ls->flag == 0)
		e_print(tree, ls);
	if (ls->big_r == 0)
		print(tree, ls);
	/*else if (ls->i == 1)
		i_flag_print(tree, ls);*/
	if (ls->big_r == 1)
	{
		if (ls->flag == 0)
		{
			//last_dir_check(tree, ls);
			/*if (ls->l == 1)
			{
				ft_putstr("total");
				ft_putchar(' ');
				ft_putnbr(ls->blocks);
				ft_putchar('\n');
				l_flag_print(tree, ls);
			}
			else*/
				print(tree, ls);
			//ft_putchar('\n');
		}
		else if (ls->flag == 2)
		{
			//last_dir_check(tree, ls);
			print(tree, ls);
			ls->ind = 3;
			/*if (ls->ind == 0)
				ft_putchar('\n');*/
			big_r_flag_print(tree, ls);
		}
		//ft_putchar('\n');
		//ft_putendl(tree->field);
		//big_r_flag_print(tree, ls);
		//ft_putchar('\n');
	}
/*	else if (ls->l == 1)
	{
		ft_putstr("total");
		ft_putchar(' ');
		ft_putnbr(ls->blocks);
		ft_putchar('\n');
		l_flag_print(tree, ls);
	}*/
	ls->flag = 0;
	return (0);
}