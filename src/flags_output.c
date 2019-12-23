/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:25:24 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/23 14:34:04 by emaveric         ###   ########.fr       */
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

void	l_flag_print(struct s_node *tree, t_ls *ls)
{
	if (ls->flag == 2 || (ls->flag == 0 && files(tree, ".") == 0))
		if (ft_strname(tree->field, '/')[0] != '.' || ls->a == 1)
		{
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
		}
}

void	i_flag_print(struct s_node *tree, t_ls *ls)
{
	if (ls->flag == 2 || (ls->flag == 0 && files(tree, ".") == 0))
		if (ft_strname(tree->field, '/')[0] != '.' || ls->a == 1)
		{
			if (ls->col->str_ino)
				free(ls->col->str_ino);
			if (ls->col->str_link)
				free(ls->col->str_link);
			if (ls->col->str_size)
				free(ls->col->str_size);
			into_string(tree, ls);
			ft_putstr(ls->col->str_ino);
			ft_putchar(' ');
		}
}
