/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:25:24 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/19 17:22:10 by emaveric         ###   ########.fr       */
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
			/*if (ls->ind == 3 && tree->flag != 1)
			*//*	if (ft_strcmp(ft_strname(tree->field, '/'), ".") != 0 &&
					ft_strcmp(ft_strname(tree->field, '/'), "..") != 0)*//*
				{
					ft_putchar('\n');
					last_dir_check(tree, ls);
				}
			if (ls->ind == 1 && tree->flag != 1)
				{
					ft_putchar('\n');
					//ls->ind = 3;
				}*/
		/*	if (ft_strcmp(ft_strname(tree->field, '/'), ".") != 0 &&
				ft_strcmp(ft_strname(tree->field, '/'), "..") != 0 &&
					(ft_strname(tree->field, '/')[0] != '.' || ls->a == 1)
					&& tree->mode[0] != 'l')*/
			if ((ft_strname(tree->field, '/')[0] != '.' || ls->a == 1) &&
				tree->mode[0] != 'l' && tree->flag != 1)
			{
				if (ls->l != 1)
					ft_putchar('\n');
				if (ls->blocks != 0 || ls->a == 1)
					ft_putchar('\n');
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
			//ft_putendl(into_string(tree, ls));
			 /*ft_putstr(tree->mode);
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
			 ft_putendl(ft_strname(tree->field, '/'));*/
			if (ls->col->str_ino)
				free(ls->col->str_ino);
			if (ls->col->str_link)
				free(ls->col->str_link);
			if (ls->col->str_size)
				free(ls->col->str_size);
			into_string(tree, ls);
			ft_putstr(tree->mode);
			ft_putstr(ls->col->str_link);
			ft_putstr(tree->uid);
			ft_putchar(' ');
			ft_putstr(tree->gid);
			ft_putstr(ls->col->str_size);
			tree->time = ft_strncut(tree->time, 4, 16);
			ft_putstr(tree->time);
			ft_putchar(' ');
			if (tree->mode[0] == 'l')
			{
				ft_putstr(ft_strname(tree->field, '/'));
				ft_putstr(" -> ");
				ft_putendl(tree->str_link);
				free(tree->str_link);
			}
			else
				ft_putendl(ft_strname(tree->field, '/'));
			/*free(ls->col->str_link);
			free(ls->col->str_size);*/
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
			//ft_putnbr(tree->ino);
			if (ls->col->str_ino)
				free(ls->col->str_ino);
			if (ls->col->str_link)
				free(ls->col->str_link);
			if (ls->col->str_size)
				free(ls->col->str_size);
		/*	max_ino_len(tree, ls);*/
			into_string(tree, ls);
			ft_putstr(ls->col->str_ino);
		//	free(ls->col->str_ino);
			ft_putchar(' ');
		}
}