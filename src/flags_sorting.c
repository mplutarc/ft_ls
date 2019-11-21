/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:51:41 by emaveric          #+#    #+#             */
/*   Updated: 2019/11/21 20:53:01 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

struct s_node	*addnode_flag_t(char *str, struct s_node *tree, struct stat buf, t_ls *ls)
{
	if (tree == NULL)     // Если дерева нет, то формируем корень
	{
		tree = tree_create(str, buf, ls);
		ls->sec = tree->sec;
		/*if (!(tree = (struct s_node *)malloc(sizeof(struct s_node))))
			return (NULL);
		tree->field = str;   //поле данных
		tree->ino = buf.st_ino;
		tree->left = NULL;
		tree->right = NULL; //ветви инициализируем пустотой*/
	}
	else     // иначе
	{
		printf("\nTIME:field %s tree %ld buf %ld\n", tree->field, ls->sec, (long int)&buf.st_ctimespec);
		if (ls->sec > tree->sec)   //Если элемент str меньше корневого, уходим влево
			tree->left = addnode_flag_t(str, tree->left, buf, ls); //Рекурсивно добавляем элемент
		else  //иначе уходим вправо
			tree->right = addnode_flag_t(str, tree->right, buf, ls); //Рекурсивно добавляем элемент
	}
	return (tree);
}

struct s_node	*addnode_flag_r(char *str, struct s_node *tree, struct stat buf, t_ls *ls)
{
	if (tree == NULL)     // Если дерева нет, то формируем корень
	{
		tree = tree_create(str, buf, ls);
		/*if (!(tree = (struct s_node *)malloc(sizeof(struct s_node))))
			return (NULL);
		tree->field = str;   //поле данных
		tree->ino = buf.st_ino;
		tree->left = NULL;
		tree->right = NULL; //ветви инициализируем пустотой*/
	}
	else     // иначе
	{
		printf("\n%s\n", str);
		if (ft_strcmp(str, tree->field) > 0)   //Если элемент str меньше корневого, уходим влево
			tree->left = addnode_flag_r(str, tree->left, buf, ls); //Рекурсивно добавляем элемент
		else  //иначе уходим вправо
			tree->right = addnode_flag_r(str, tree->right, buf, ls); //Рекурсивно добавляем элемент
	}
	return (tree);
}