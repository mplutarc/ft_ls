/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:51:41 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/05 17:34:13 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

struct s_node	*addnode_flag_t(char *str, struct s_node *tree, struct stat buf, t_ls *ls)
{
	char 	*tmp; ////////
	char 	*new;

	if (tree == NULL)     // Если дерева нет, то формируем корень
	{
		if (!(tree = tree_create(str, buf, ls)))
		{
		//	free(str);
			//free_tree(tree);
			return(NULL);
		}
		//	return (NULL);
		tree->flag = 0;
		if (!(ft_strname(tree->field, '/'), ".") && !(ft_strname(tree->field, '/'), ".."))
		{
			//free_tree(tree);
			return (NULL);
		}
			//return (NULL);
		else if (ft_strcmp((tmp = ft_strname(tree->field, '/')), ".") == 0 ||
			ft_strcmp(new = ft_strname(tree->field, '/'), "..") == 0)
			tree->flag = 1;
		/*if (tmp != NULL)
			free(&tmp);
		if (new != NULL)
			free(&new);*/
		/*if (!(tree = (struct s_node *)malloc(sizeof(struct s_node))))
			return (NULL);
		tree->field = str;   //поле данных
		tree->ino = buf.st_ino;
		tree->left = NULL;
		tree->right = NULL; //ветви инициализируем пустотой*/
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
				tree->left = addnode_flag_t(str, tree->left, buf, ls); //Рекурсивно добавляем элемент
			else if (ls->r == 0)
				tree->right = addnode_flag_t(str, tree->right, buf, ls); //Рекурсивно добавляем элемент
		}
	}
	return (tree);
}

struct s_node	*addnode_flag_r(char *str, struct s_node *tree, struct stat buf, t_ls *ls)
{
	char *tmp; /////////

	if (tree == NULL)     // Если дерева нет, то формируем корень
	{
		if (!(tree = tree_create(str, buf, ls)))
			return (NULL);
		tree->flag = 0;
		if (ft_strcmp(tmp = ft_strname(tree->field, '/'), ".") == 0 ||
			ft_strcmp(tmp = ft_strname(tree->field, '/'), "..") == 0)
			tree->flag = 1;
		/*if (!(tree = (struct s_node *)malloc(sizeof(struct s_node))))
			return (NULL);
		tree->field = str;   //поле данных
		tree->ino = buf.st_ino;
		tree->left = NULL;
		tree->right = NULL; //ветви инициализируем пустотой*/
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