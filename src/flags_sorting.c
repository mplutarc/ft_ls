/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:51:41 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/24 15:54:59 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

struct s_node	*addnode_flag_t_p3(char *str, struct s_node *tree, struct stat buf, t_ls *ls)
{
	if (ls->r == 1)
	{
		if (!(tree->left = addnode_flag_t(str, tree->left, buf, ls)))
		{
			free_tree(tree);
			return (NULL);
		}
	}
	else if (ls->r == 0)
		if (!(tree->right = addnode_flag_t(str, tree->right, buf, ls)))
		{
			free_tree(tree);
			return (NULL);
		}
	return (tree);
}

struct s_node	*addnode_flag_t_p2(char *str, struct s_node *tree, struct stat buf, t_ls *ls)
{
	if (ls->sec > tree->sec)
	{
		if (ls->r == 0)
		{
			if (!(tree->left = addnode_flag_t(str, tree->left, buf, ls)))
			{
				free_tree(tree);
				return (NULL);
			}
		}
		else if (ls->r == 1)
			if (!(tree->right = addnode_flag_t(str, tree->right, buf, ls)))
			{
				free_tree(tree);
				return (NULL);
			}
	}
	else
		if (!(tree = addnode_flag_t_p3(str, tree, buf, ls)))
			return (NULL);
	return (tree);
}

struct s_node	*addnode_flag_t(char *str, struct s_node *tree, struct stat buf, t_ls *ls)
{
	if (tree == NULL)
	{
		if (!(tree = tree_create(str, buf, ls)))
			return (NULL);
		tree->flag = 0;
		if (ft_strcmp((ft_strname(tree->field, '/')), ".") == 0 ||
			ft_strcmp(ft_strname(tree->field, '/'), "..") == 0)
			tree->flag = 1;
	}
	else
		if (!(tree = addnode_flag_t_p2(str, tree, buf, ls)))
			return (NULL);
	return (tree);
}

struct s_node	*addnode_flag_r(char *str, struct s_node *tree, struct stat buf, t_ls *ls)
{
	if (tree == NULL)
	{
		if (!(tree = tree_create(str, buf, ls)))
			return (NULL);
		tree->flag = 0;
		if (ft_strcmp(ft_strname(tree->field, '/'), ".") == 0 ||
			ft_strcmp(ft_strname(tree->field, '/'), "..") == 0)
			tree->flag = 1;
	}
	else
	{
		if (ft_strcmp(str, tree->field) > 0)
			tree->left = addnode_flag_r(str, tree->left, buf, ls);
		else
			tree->right = addnode_flag_r(str, tree->right, buf, ls);
	}
	return (tree);
}
