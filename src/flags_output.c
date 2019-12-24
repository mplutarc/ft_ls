/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:25:24 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/24 16:18:04 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	big_r_flag_print(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{
		big_r_flag_print(tree->left, ls);
		if (tree->mode[0] == 'd')
		{
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
			}
		}
		big_r_flag_print(tree->right, ls);
	}
}


void	l_flag_print_link(struct s_node *tree)
{
	if (tree->mode[0] == 'l')
	{
		ft_putstr(ft_strname(tree->field, '/'));
		ft_putstr(" -> ");
		ft_putstr(tree->str_link);
	}
	else
		ft_putstr(ft_strname(tree->field, '/'));
}

void	l_flag_print(struct s_node *tree, t_ls *ls)
{
	if (ls->flag == 2 || (ls->flag == 0 && files(tree->field, ".") == 0))
		if (ft_strname(tree->field, '/')[0] != '.' || ls->a == 1)
		{
			if (ls->col->str_ino)
				free(ls->col->str_ino);
			if (ls->col->str_link)
				free(ls->col->str_link);
			if (ls->col->str_size)
				free(ls->col->str_size);
			if (ls->col->str_uid)
				free(ls->col->str_uid);
			if (ls->col->str_gid)
				free(ls->col->str_gid);
			into_string(tree, ls);
			ft_putstr(tree->mode);
			ft_putstr(ls->col->str_link);
			ft_putstr(ls->col->str_uid);
			ft_putstr(ls->col->str_gid);
			ft_putstr(ls->col->str_size);
			tree->time = ft_strncut(tree->time, 4, 16);
			ft_putstr(tree->time);
			ft_putchar(' ');
			l_flag_print_link(tree);
		}
}

void	i_flag_print(struct s_node *tree, t_ls *ls)
{
	if (ls->flag == 2 || (ls->flag == 0 && files(tree->field, ".") == 0))
		if (ft_strname(tree->field, '/')[0] != '.' || ls->a == 1)
		{
			if (ls->col->str_ino)
				free(ls->col->str_ino);
			if (ls->col->str_link)
				free(ls->col->str_link);
			if (ls->col->str_size)
				free(ls->col->str_size);
			if (ls->col->str_uid)
				free(ls->col->str_uid);
			if (ls->col->str_gid)
				free(ls->col->str_gid);
			into_string(tree, ls);
			ft_putstr(ls->col->str_ino);
			ft_putchar(' ');
		}
}
