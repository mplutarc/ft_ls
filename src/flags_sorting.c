/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:51:41 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/11 16:52:57 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

struct s_node	*addnode_flag_t(char *str, struct s_node *tree, struct stat buf, t_ls *ls)
{
	if (tree == NULL)     // Если дерева нет, то формируем корень
	{
		if (!(tree = tree_create(str, buf, ls)))
			return(NULL);
		tree->flag = 0;
		if (ft_strcmp((ft_strname(tree->field, '/')), ".") == 0 ||
			ft_strcmp(ft_strname(tree->field, '/'), "..") == 0)
			tree->flag = 1;
	}
	else     // иначе
	{
		if (ls->sec > tree->sec)   //Если элемент str меньше корневого, уходим влево
		{
			if (ls->r == 0)
			{
				if (!(tree->left = addnode_flag_t(str, tree->left, buf, ls)))
				{
					free_tree(tree);
					return (NULL);
				}//Рекурсивно добавляем элемент
			}
			else if (ls->r == 1)
				if (!(tree->right = addnode_flag_t(str, tree->right, buf, ls)))
				{
					free_tree(tree);
					return (NULL);
				}
		}
		else  //иначе уходим вправо
		{
			if (ls->r == 1)
			{
				if (!(tree->left = addnode_flag_t(str, tree->left, buf, ls)))
				{
					free_tree(tree);
					return (NULL);
				}//Рекурсивно добавляем элемент
			}
			else if (ls->r == 0)
				if (!(tree->right = addnode_flag_t(str, tree->right, buf, ls)))
				{
					free_tree(tree);
					return (NULL);
				} //Рекурсивно добавляем элемент
		}
	}
	return (tree);
}

struct s_node	*addnode_flag_r(char *str, struct s_node *tree, struct stat buf, t_ls *ls)
{
	if (tree == NULL)     // Если дерева нет, то формируем корень
	{
		if (!(tree = tree_create(str, buf, ls)))
			return (NULL);
		tree->flag = 0;
		if (ft_strcmp(ft_strname(tree->field, '/'), ".") == 0 ||
			ft_strcmp(ft_strname(tree->field, '/'), "..") == 0)
			tree->flag = 1;
	}
	else     // иначе
	{
		if (ft_strcmp(str, tree->field) > 0)   //Если элемент str меньше корневого, уходим влево
			tree->left = addnode_flag_r(str, tree->left, buf, ls); //Рекурсивно добавляем элемент
		else  //иначе уходим вправо
			tree->right = addnode_flag_r(str, tree->right, buf, ls); //Рекурсивно добавляем элемент
	}
	return (tree);
}