/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:11:32 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/19 17:49:25 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	e_print(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{
		e_print(tree->left, ls);
		if (files(tree, ".") == ERROR)
		{
			tree->mode[0] = 'e';
			ls->ac--;
			directory(tree->field, ls);
		}
		e_print(tree->right, ls);
	}
}

void	print(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{
		print(tree->left, ls);
		if (ls->flag == 2 || (ls->flag == 0 && tree->mode[0] == '-'))
		{
			if ((ft_strname(tree->field, '/'))[0] != '.' || ls->a == 1)
			{
				if (ls->i == 1)
					i_flag_print(tree, ls);
				if (ls->l == 1)
					l_flag_print(tree, ls);
				else
				{
					ft_putstr(ft_strname(tree->field, '/'));
					ft_putchar('\t');
				}
			}
		}
		else if (tree->mode[0] == 'd')
		{
			if (ls->ac > 0 && ls->flag == 0)
			{
				ft_putstr(tree->field);
				ft_putstr(":\n");
				if (ls->point != 0)
					ls->ac--;
				ls->point = 1;
			}
			directory(tree->field, ls);
			if (ls->ac > 0)
			{
				ft_putstr("\n");
				if ((ls->blocks != 0 || ls->a == 1) && ls->l != 1)
					ft_putstr("\n");
			}
		}
		print(tree->right, ls);
	}
}

int		output(t_ls *ls, struct s_node *tree)
{
	ls->col->max_ino = 0;
	ls->col->max_size = 0;
	ls->col->max_link = 0;
	if (ls->l == 1 || ls->i == 1)
		max_len(tree, ls);
	if (ls->flag == 0)
		e_print(tree, ls);
	if (ls->l == 1 && ls->flag != 0 && (ls->blocks != 0 || ls->a == 1))
	{
		ft_putstr("total");
		ft_putchar(' ');
		ft_putnbr(ls->blocks);
		ft_putchar('\n');
	}
	if (ls->big_r == 0)
		print(tree, ls);
	if (ls->big_r == 1)
	{
		if (ls->flag == 0)
			print(tree, ls);
		else if (ls->flag == 2)
		{
			print(tree, ls);
			ls->ind = 3;
			big_r_flag_print(tree, ls);
		}
	}
	ls->flag = 0;
	return (0);
}
