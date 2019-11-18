/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:25:24 by emaveric          #+#    #+#             */
/*   Updated: 2019/11/18 17:19:31 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


void	big_r_flag_print(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		big_r_flag_print(tree->left, ls);  //Рекурсивная функция вывода левого поддерева
		if ((opendir(tree->field) || fopen(tree->field, "rt")))
		{
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

void    l_flag_print(struct s_node *tree, t_ls *ls)
{
    if (tree != NULL)
    {      //Пока не встретится пустой узел
		l_flag_print(tree->left, ls);  //Рекурсивная функция вывода левого поддерева
        if ((opendir(tree->field) || fopen(tree->field, "rt")))
        {
            if (ls->flag == 2) //&& (ls->f_sum == 0 || ls->r == 1))) /*||
                //(!opendir(tree->field) && fopen(tree->field, "rt"))) //&& ls->big_r == 0)//(!opendir(tree->field) && fopen(tree->field, "rt"))
			{
				tree->field = ft_strcut(tree->field, '/');
				if (tree->field[0] != '.')
				{
					ft_putstr(tree->mode);
					ft_putchar(' ');
					ft_putstr(tree->uid);
					ft_putchar(' ');
					ft_putstr(tree->gid);
					ft_putchar(' ');
					ft_putnbr(tree->links);
					ft_putchar(' ');
					ft_putnbr(tree->size);
					ft_putchar(' ');
					ft_putendl(tree->field);
				}
            }
/*			else if (!opendir(tree->field) && fopen(tree->field, "rt"))
				ft_putendl(tree->field);*/
            else /*if (ft_strcmp(ft_strcut(tree->field, '/'), ".") != 0 &&
					ft_strcmp(ft_strcut(tree->field, '/'), "..") != 0)*/
                directory(tree->field, ls);
        }
		l_flag_print(tree->right, ls); //Рекурсивная функция вывода правого поддерева
    }
}

void    a_flag_print(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		a_flag_print(tree->left, ls);  //Рекурсивная функция вывода левого поддерева
		if ((opendir(tree->field) || fopen(tree->field, "rt")))
		{
			if (ls->flag == 2) //&& (ls->f_sum == 0 || ls->r == 1))) /*||
				//(!opendir(tree->field) && fopen(tree->field, "rt"))) //&& ls->big_r == 0)//(!opendir(tree->field) && fopen(tree->field, "rt"))
			{
				tree->field = ft_strcut(tree->field, '/');
				ft_putstr(tree->field);
				ft_putchar('\t');
			}
/*			else if (!opendir(tree->field) && fopen(tree->field, "rt"))
				ft_putendl(tree->field);*/
			else /*if (ft_strcmp(ft_strcut(tree->field, '/'), ".") != 0 &&
					ft_strcmp(ft_strcut(tree->field, '/'), "..") != 0)*/
				directory(tree->field, ls);
		}
		a_flag_print(tree->right, ls); //Рекурсивная функция вывода правого поддерева
	}
}

void    i_flag_print(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		i_flag_print(tree->left, ls);  //Рекурсивная функция вывода левого поддерева
		if ((opendir(tree->field) || fopen(tree->field, "rt")))
		{
			if (ls->flag == 2) //&& (ls->f_sum == 0 || ls->r == 1))) /*||
				//(!opendir(tree->field) && fopen(tree->field, "rt"))) //&& ls->big_r == 0)//(!opendir(tree->field) && fopen(tree->field, "rt"))
			{
				tree->field = ft_strcut(tree->field, '/');
				if (tree->field[0] != '.')
				{
					ft_putnbr(tree->ino);
					ft_putchar(' ');
					ft_putstr(tree->field);
					ft_putchar('\t');
				}
			}
/*			else if (!opendir(tree->field) && fopen(tree->field, "rt"))
				ft_putendl(tree->field);*/
			else /*if (ft_strcmp(ft_strcut(tree->field, '/'), ".") != 0 &&
					ft_strcmp(ft_strcut(tree->field, '/'), "..") != 0)*/
				directory(tree->field, ls);
		}
		i_flag_print(tree->right, ls); //Рекурсивная функция вывода правого поддерева
	}
}