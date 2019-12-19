/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:41:40 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/19 17:55:27 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	free_ls(t_ls *ls)
{
	if (ls->f_index)
		free(ls->f_index);
	if (ls->col->str_ino)
		free(ls->col->str_ino);
	if (ls->col->str_link)
		free(ls->col->str_link);
	if (ls->col->str_size)
		free(ls->col->str_size);
	free(ls->col);
	free(ls);
}

void	free_first_tree(struct s_node *tree)
{
	if (tree != NULL)
	{
		free_first_tree(tree->left);
		free_first_tree(tree->right);
		tree->field = NULL;
		free(tree->uid);
		tree->uid = NULL;
		free(tree->gid);
		tree->gid = NULL;
		free(tree->mode);
		tree->mode = NULL;
		free(tree->time);
		tree->time = NULL;
	}
}

void	free_tree(struct s_node *tree)
{
	if (tree != NULL)
	{
		free_tree(tree->left);
		free_tree(tree->right);
		if (tree->field)
			free(tree->field);
		if (tree->mode)
			free(tree->mode);
		if (tree->gid)
			free(tree->gid);
		if (tree->uid)
			free(tree->uid);
		if (tree->time)
			free(tree->time);
		if (tree->right)
			tree->right = NULL;
		if (tree->left)
			tree->left = NULL;
		free(tree);
		tree = NULL;
	}
}
