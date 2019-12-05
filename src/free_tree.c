/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:41:40 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/05 17:34:13 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		free_ls(t_ls *ls)
{
	if (ls->f_index)
		free(ls->f_index);
	free(ls);
}

void	free_tree(struct s_node *tree)
{
	struct s_node *sub_tree;

	if (tree != NULL)
	{      //Пока не встретится пустой узел
		free_tree(tree->left);  //Рекурсивная функция вывода левого поддерева
		free_tree(tree->right);
		if (tree->left == NULL && tree->right == NULL)
		{
			if (tree->field)
				free(tree->field);
			if (tree->time)
				free(tree->time);
			if (tree->mode)
				free(tree->mode);
			if (tree->gid)
				free(tree->gid);
			if (tree->uid)
				free(tree->uid);
			sub_tree = tree;
			free(tree);
			tree = NULL;
		}
	//	free_tree(sub_tree->right); //Рекурсивная функция вывода правого поддерева
	}
}